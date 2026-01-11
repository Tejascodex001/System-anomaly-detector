#ifndef PROC_READER_HPP
#define PROC_READER_HPP

#include <cstdint>
#include <string>

struct cpusnap {
    std::string cpu_name;
    std::uint64_t user_time = 0;
    std::uint64_t nice_time = 0;
    std::uint64_t system_kernel_time = 0;
    std::uint64_t idle_time = 0;
    std::uint64_t iowait_time = 0;
    std::uint64_t irq_time = 0;
    std::uint64_t softirq_time = 0;
};


struct memsnap{
    std::uint64_t memt_val_kb = 0;
    std::uint64_t mema_val_kb = 0;
};

cpusnap read_cpu();
memsnap read_meminfo();

#endif