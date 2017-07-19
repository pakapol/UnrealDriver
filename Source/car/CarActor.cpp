// Fill out your copyright notice in the Description page of Project Settings.

#include "CarActor.h"
#include <zmq.hpp>
#include <iostream>
#include <unistd.h>

#include <vector>
#include <string>
#include <sstream>

#include <json.hpp>
using json = nlohmann::json;

void printVector(std::vector<float> * arr){
    for (size_t i = 0; i < (*arr).size(); i++){
        std::cout << (*arr)[i] << " ";
    }
    std::cout << std::endl;
}

namespace automotive {
    struct vehicle_defs {
        int id;
        int cls;
        float length;
        float width;
    };
    
    // note: we only plan to send over a single timestep at a time.
    struct vehicle_states{
        std::vector<double> x;
        std::vector<double> y;
        std::vector<double> theta;
        std::vector<double> v;
    };
    
    void to_json(json& j, const vehicle_states& p){
        j = json{
            {"x", p.x},
            {"y", p.y},
            {"theta", p.theta},
            {"v", p.v}};
    }
    
    void from_json(const json& j, vehicle_states& p){
        p.x = j.at("x").get<std::vector<double>>();
        p.y = j.at("y").get<std::vector<double>>();
        p.theta = j.at("theta").get<std::vector<double>>();
        p.v = j.at("v").get<std::vector<double>>();
        
    }
}

void to_julia(std::vector<double> xs, std::vector<double> ys, std::vector<double> theta, std::vector<double> v) {
    automotive::vehicle_states vs0 {xs, ys, theta, v};
    json j = vs0;
    std::string s = j.dump();
    
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REQ);
    //socket.bind("tcp://*:5555");
    socket.connect("tcp://localhost:5555");

    // send request
    zmq::message_t request(s.size());
    memcpy((void*) request.data(), (s.c_str()), s.size());
    socket.send(request);

    // receive reply
    zmq::message_t reply;
    socket.recv(&reply);

    //process reply
    std::string replyMessage = std::string(static_cast<char*>(reply.data()), reply.size());
    std::stringstream iss( replyMessage );

    // Print out received message
    float number;
    std::vector<float> action;
    while( iss >> number ){
        action.push_back( number );
    }
    
//    zmq::message_t request;
//    std::cout << "Waiting on message..." << std::endl;
//    socket.recv(&request);
//        
//    std::cout << "Sending message." << std::endl;
//    zmq::message_t reply(s.size());
//    memcpy((void *) reply.data(), (s.c_str()), s.size());
//    socket.send(reply);
    
}

// Sets default values
ACarActor::ACarActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACarActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACarActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    FVector loc = GetActorLocation();
    FRotator rot = GetActorRotation();
    FVector Velocity = GetActorRotation().Vector() * Speed;
    double acceleration = 0.0;
    if (Speed < 5.0) { acceleration = 1.0; } // Should Retrieve this from Julia Agent
    double turnRate = 0.5;   // Should Retrieve this from Julia Agent
    double newSpeed = Speed + acceleration * DeltaTime;
    double newYaw = rot.Yaw + turnRate * Speed * DeltaTime;

    rot.Yaw = newYaw;
    FVector newVelocity = rot.Vector() * newSpeed;
    
    loc.X += (Velocity.X + newVelocity.X) * DeltaTime / 2;
    loc.Y += (Velocity.Y + newVelocity.Y) * DeltaTime / 2;
    
    Speed = newSpeed;
    
    SetActorLocation(loc);
    SetActorRotation(rot);
    
    std::vector<double> xs({loc.X});
    std::vector<double> ys({loc.Y});
    std::vector<double> theta({rot.Yaw});
    std::vector<double> v({Speed});
    to_julia(xs, ys, theta, v);
    
}

