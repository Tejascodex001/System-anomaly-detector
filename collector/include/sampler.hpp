#ifndef SAMPLER_HPP
#define SAMPLER_HPP

#include<string>
#include <cstdint>
#include <chrono>

struct sample{
    std::time_t timeStamp;
    double cpu_usage;
    double mem_usage;
    double mem_mean;
    double cpu_mean;
    double cpu_std;
    double mem_std;
    double mem_z;
    double cpu_z;
    double anomaly_score;
    enum State_type{
        NORMAL,
        WARNING,
        ANOMALY
    };
    State_type state;
};

sample sample_usage();


#endif