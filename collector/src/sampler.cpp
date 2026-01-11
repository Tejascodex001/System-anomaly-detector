#include <cstdint>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;
using namespace std;

#include "sampler.hpp"
#include "proc_reader.hpp"

sample sample_usage(){
    cpusnap cpuatt, cpuatt1;
    memsnap mematt;
    sample usage;
    uint64_t total_delta, idle_delta, user_delta, nice_delta, system_delta, iowait_delta, irq_delta, 
    softirq_delta;
    double usedmem;

    cpuatt = read_cpu();
    this_thread::sleep_for(1s);
    cpuatt1 = read_cpu();
    mematt = read_meminfo();

    user_delta = cpuatt1.user_time - cpuatt.user_time;
    nice_delta = cpuatt1.nice_time - cpuatt.nice_time;
    system_delta = cpuatt1.system_kernel_time - cpuatt.system_kernel_time;
    idle_delta = cpuatt1.idle_time - cpuatt.idle_time;
    iowait_delta = cpuatt1.iowait_time - cpuatt.iowait_time;
    irq_delta = cpuatt1.irq_time - cpuatt.irq_time;
    softirq_delta = cpuatt1.softirq_time - cpuatt.softirq_time;
    if (mematt.memt_val_kb > 0) usedmem = double(mematt.memt_val_kb) - double(mematt.mema_val_kb);
    else usedmem = 0;

    total_delta = user_delta + nice_delta + system_delta + idle_delta + iowait_delta + irq_delta + softirq_delta;
    usage.cpu_usage = double(total_delta - idle_delta)/double(total_delta);
    usage.mem_usage = usedmem/double(mematt.memt_val_kb);
    auto timer = chrono::system_clock::to_time_t(chrono::system_clock::now());
    usage.timeStamp = timer;
    return usage;
}