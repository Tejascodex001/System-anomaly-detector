#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <chrono>
#include <string>

#include "proc_reader.hpp"

using namespace std::chrono_literals;
using namespace std;

cpusnap read_cpu(){
    cpusnap cpuatt;
    string cpupath = "/proc/stat";
    ifstream inputFile(cpupath);
    if(!inputFile.is_open()) { cout << "error not open" << endl; exit(0);}
    else {
        string line;
        getline(inputFile,line);

        istringstream(line) >> cpuatt.cpu_name >> cpuatt.user_time >> 
        cpuatt.nice_time >> cpuatt.system_kernel_time >> cpuatt.idle_time >> cpuatt.iowait_time >> 
        cpuatt.irq_time >> cpuatt.softirq_time;

        inputFile.close();
    }
    return cpuatt;
}

memsnap read_meminfo(){
    memsnap mematt;
    string mempath = "/proc/meminfo";
    ifstream inputFile(mempath);
    if(!inputFile.is_open()) { cout << "error not open" << endl; exit(0);}
    else {
        string line;
        bool found_total = false;
        bool found_avail = false;
        string temp, temp1;
        while(getline(inputFile,line)){
            if(line.rfind("MemTotal", 0) == 0){
                istringstream(line) >> temp >> mematt.memt_val_kb;
                found_total = true;
            }
            if(line.rfind("MemAvailable", 0) == 0){
                istringstream(line) >> temp1 >> mematt.mema_val_kb;
                found_avail = true;
            }
            if (found_total && found_avail) break;
        }
        inputFile.close();
    }   
    return mematt;
}
