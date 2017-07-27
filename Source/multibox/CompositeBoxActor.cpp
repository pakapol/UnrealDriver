// Fill out your copyright notice in the Description page of Project Settings.

#include "CompositeBoxActor.h"

#include <zmq.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <json.hpp>

#include "BoxActor.h"
using json = nlohmann::json;

// Vehicle properties
std::vector<int> ids({0, 1, 2, 3});
std::vector<int> clss({2, 2, 2, 2});
std::vector<double> lengths({2.0, 2.0, 2.0, 2.0});
std::vector<double> widths({1.0, 1.0, 1.0, 1.0});
int n_vehicles = 4;

namespace automotive {
    struct vehicle_defs {
        std::vector<int> id;
        std::vector<int> cls;
        std::vector<double> length;
        std::vector<double> width;
        int n_vehicles;
    };

    // note: we only plan to send over a single timestep at a time.
    struct vehicle_states{
        std::vector<float> x;
        std::vector<float> y;
        std::vector<double> theta;
        std::vector<double> v;
    };

    // JSON functions for vehicle_defs
    void to_json(json& j, const vehicle_defs& p){
        j = json{
            {"id", p.id},
            {"cls", p.cls},
            {"length", p.length},
            {"width", p.width},
            {"n_vehicles", p.n_vehicles}};
    }

    void from_json(const json& j, vehicle_defs& p){
        p.id = j.at("x").get<std::vector<int>>();
        p.cls = j.at("y").get<std::vector<int>>();
        p.length = j.at("theta").get<std::vector<double>>();
        p.width = j.at("v").get<std::vector<double>>();
        p.n_vehicles = j.at("n_vehicles").get<int>();
    }

    // JSON functions for vehicle_states
    void to_json(json& j, const vehicle_states& p){
        j = json{
            {"x", p.x},
            {"y", p.y},
            {"theta", p.theta},
            {"v", p.v}};
    }

    void from_json(const json& j, vehicle_states& p){
        p.x = j.at("x").get<std::vector<float>>();
        p.y = j.at("y").get<std::vector<float>>();
        p.theta = j.at("theta").get<std::vector<double>>();
        p.v = j.at("v").get<std::vector<double>>();

    }
}

std::string state_message(std::vector<float> xs, std::vector<float> ys, std::vector<double> theta, std::vector<double> v){
    automotive::vehicle_defs vds {ids, clss, lengths, widths, n_vehicles};
    json j_vds = vds;
    automotive::vehicle_states vss {xs, ys, theta, v};
    json j_vss = vss;
    json j;
    j["vehicle_defs"] = j_vds;
    j["vehicle_states"] = j_vss;
    std::string s = j.dump();
    return s;
}

std::vector<float> get_action_from_julia(zmq::socket_t* socket_ptr, std::string s) {
    // send request
    zmq::message_t request(s.size());
    memcpy((void*) request.data(), s.c_str(), s.size());
    socket_ptr->send(request);

    // receive reply
    zmq::message_t reply;
    socket_ptr->recv(&reply);

    // process reply
    std::string replyMessage = std::string(static_cast<char*>(reply.data()), reply.size());
    std::stringstream iss(replyMessage);

    // Print out received message
    float number;
    std::vector<float> action;
    while (iss >> number) {
        action.push_back(number);
    }
    return action;
}

// Sets default values
ACompositeBoxActor::ACompositeBoxActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACompositeBoxActor::BeginPlay()
{
    Super::BeginPlay();
    // Connect to ZMQ
    zmq::context_t* ctx_p = new zmq::context_t(1);
    socket_p = new zmq::socket_t(*ctx_p, ZMQ_REQ);
    
    socket_p->connect("tcp://localhost:5555");
    // Spawn all actors
    // ** This would specify initial location of the vehicles
    for (int i = 0; i < n_vehicles; ++i) {
        ABoxActor* newActor = GetWorld()->SpawnActor<ABoxActor>(FVector::ZeroVector, FRotator::ZeroRotator);
        boxActors.push_back(newActor);
        FVector dims = FVector(lengths[i] * 5.0, widths[i] * 5.0, 10.0);
        FVector loc = FVector(20.f * i, 20.f * i, 20.f);
        newActor->InitVehicle(dims, loc);
    }
}

// Called every frame
void ACompositeBoxActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    // Get states of all vehicles
    std::vector<float> xs;
    std::vector<float> ys;
    std::vector<double> theta;
    std::vector<double> v;
    for (int i = 0; i < n_vehicles; ++i) {
        xs.push_back(boxActors[i]->GetActorLocation().X);
        ys.push_back(boxActors[i]->GetActorLocation().Y);
        theta.push_back((double) boxActors[i]->GetActorRotation().Yaw);
        v.push_back(boxActors[i]->Speed);
    }
    // Send and receive
    std::vector<float> action = get_action_from_julia(socket_p, state_message(xs, ys, theta, v));
    // Update
    boxActors[0]->Update(DeltaTime, action[0], action[1]);
    for (int i = 1; i < n_vehicles; ++i) {
        boxActors[i]->Update(DeltaTime, 0.5, 0.5);
    }
}
