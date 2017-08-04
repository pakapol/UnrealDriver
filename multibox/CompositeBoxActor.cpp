// Fill out your copyright notice in the Description page of Project Settings.


#include "CompositeBoxActor.h"

#include <zmq.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <json.hpp>
#include "FileHelper.h"

#include "BoxActor.h"

#define NEW_DT 0.1
#define SCALE_FACTOR 10.0
#define MAXSTEP 150

using json = nlohmann::json;

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
    
    struct traj_data {
        vehicle_defs vdefs;
        std::vector<vehicle_states> vstates;
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

automotive::traj_data read_trajdata(std::string filename) {
    
    FString ue_filename = FString(filename.c_str());
    FString result;
    std::cout << FFileHelper::LoadFileToString(result, *ue_filename);
    std::string filestr(TCHAR_TO_UTF8(*result));
    
    // std::cout << filestr << std::endl;
    
    std::istringstream input;
    input.str(filestr);
    
    std::string buffer;
    input >> buffer;
    
    /** id, cls, length, width, n_vehicles (vectors of length n_veh)
     */
    int n_vehicles, id, cls;
    double vlength, vwidth;
    std::vector<int> ids, clss;
    std::vector<double> vlengths, vwidths;
    input >> n_vehicles;

    // std::cout << "aksdjfh " << n_vehicles << std::endl;
    
    for (int i = 0; i < n_vehicles; ++i) {
        input >> id;
        input >> cls;
        input >> vlength;
        input >> vwidth;
        ids.push_back(id);
        clss.push_back(cls);
        vlengths.push_back(vlength);
        vwidths.push_back(vwidth);
    }
    automotive::vehicle_defs vdefs {ids, clss, vlengths, vwidths, n_vehicles};
    input >> buffer;
    getline(input, buffer);
    // (xs, ys, thetas)::(n_veh, n_veh, n_veh)
    float x, y, buffer2;
    double theta, v;
    std::vector<automotive::vehicle_states> vstates;
    for (int i = 0; i < MAXSTEP; ++i) {
        std::vector<float> xs, ys;
        std::vector<double> thetas, vs;
        for (int k = 0; k < n_vehicles; ++k) {
            getline(input, buffer);
            buffer.erase(std::remove(buffer.begin(), buffer.end(), '('), buffer.end());
            buffer.erase(std::remove(buffer.begin(), buffer.end(), ')'), buffer.end());
            std::istringstream iss;
            iss.str(buffer);
            iss >> buffer2;
            iss >> x;
            iss >> y;
            iss >> theta;
            for (int j = 0; j < 7; ++j) {
                iss >> buffer2;
            }
            iss >> v;
            xs.push_back(x);
            ys.push_back(y);
            thetas.push_back(theta);
            vs.push_back(v);
        }
        automotive::vehicle_states vhs {xs, ys, thetas, vs};
        vstates.push_back(vhs);
    }
    automotive::traj_data td {vdefs, vstates};
    return td;
}

std::string state_message(automotive::vehicle_defs vds, automotive::vehicle_states vss){
    json j_vds = vds;
    json j_vss = vss;
    json j;
    j["vehicle_defs"] = j_vds;
    j["vehicle_states"] = j_vss;
    std::string s = j.dump();
    // std::cout << s << std::endl;
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
    
    automotive::traj_data* traj_data_p = new automotive::traj_data(read_trajdata("/Users/pakapol/projects/UE/transfer/julia/2d_drive_data/trajdata/trajdata_ncars96_mix_VALID5.txt"));
    traj_data_gp = (void*) traj_data_p;
    
    
    // Spawn all actors
    // ** This would specify initial location of the vehicles
    
    
    for (int i = 0; i < traj_data_p->vdefs.n_vehicles; ++i) {
        ABoxActor* newActor = GetWorld()->SpawnActor<ABoxActor>(FVector::ZeroVector, FRotator::ZeroRotator);
        boxActors.push_back(newActor);
        FVector dims = FVector(traj_data_p->vdefs.length[i] * SCALE_FACTOR, traj_data_p->vdefs.width[i] * SCALE_FACTOR, traj_data_p->vdefs.width[i] * SCALE_FACTOR);
        FVector loc = FVector(traj_data_p->vstates[0].x[i] * SCALE_FACTOR, traj_data_p->vstates[0].y[i] * SCALE_FACTOR, 0);
        newActor->InitVehicle(dims, loc);
        newActor->Update(0, traj_data_p->vstates[0].x[i] * SCALE_FACTOR, traj_data_p->vstates[0].y[i] * SCALE_FACTOR, traj_data_p->vstates[0].theta[i], traj_data_p->vstates[0].v[i] * SCALE_FACTOR);
    }
    automotive::traj_data* traj_data_u = (automotive::traj_data*) traj_data_gp;
}

// Called every frame
void ACompositeBoxActor::Tick(float DeltaTime)
{
    Super::Tick(0.1);
    t += 1;
    // Get states of all vehicles
    std::vector<float> xs;
    std::vector<float> ys;
    std::vector<double> theta;
    std::vector<double> v;
    automotive::traj_data* traj_data_p = (automotive::traj_data*) traj_data_gp;
    for (int i = 0; i < traj_data_p->vdefs.n_vehicles; ++i) {
        xs.push_back(boxActors[i]->GetActorLocation().X);
        ys.push_back(boxActors[i]->GetActorLocation().Y);
        theta.push_back((double) boxActors[i]->GetActorRotation().Yaw);
        v.push_back(boxActors[i]->Speed);
    }
    // Send and receive
    std::vector<float> action = get_action_from_julia(socket_p, state_message(traj_data_p->vdefs, traj_data_p->vstates[t-1]));
    // Update
    // boxActors[0]->Act(DeltaTime, action[0] * SCALE_FACTOR, action[1]);
    
    for (int i = 0; i < traj_data_p->vdefs.n_vehicles; ++i) {
        boxActors[i]->Update(0.1, traj_data_p->vstates[t].x[i] * SCALE_FACTOR, traj_data_p->vstates[t].y[i] * SCALE_FACTOR, traj_data_p->vstates[t].theta[i], traj_data_p->vstates[t].v[i] * SCALE_FACTOR);
    }
}
