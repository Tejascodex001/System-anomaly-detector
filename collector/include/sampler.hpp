#ifndef SAMPLER_HPP
#define SAMPLER_HPP

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
};

sample sample_usage();



#endif