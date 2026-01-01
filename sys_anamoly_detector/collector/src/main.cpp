#include <cstdint>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;
using namespace std;

struct cpusnap {
    string cpu_name;
    uint64_t user_time;
    uint64_t nice_time;
    uint64_t system_kernel_time;
    uint64_t idle_time;
    uint64_t iowait_time;
    uint64_t irq_time;
    uint64_t softirq_time;
};



int main (){
    long user, nice, system_kernel, idle, iowait, irq, softirq;
    string label;
    cpusnap cpuatt, cpuatt1;
    string folderpath = "/proc/stat";

    ifstream inputFile(folderpath);
    if (inputFile.is_open()){
        string line;
        getline(inputFile, line);
        cout << line << endl;

        istringstream(line) >> cpuatt.cpu_name >> cpuatt.user_time >> 
        cpuatt.nice_time >> cpuatt.system_kernel_time >> cpuatt.idle_time >> cpuatt.iowait_time >> 
        cpuatt.irq_time >> cpuatt.softirq_time;
        inputFile.close();
    }


    this_thread::sleep_for(1s);

    ifstream inputFile1(folderpath);
    if (inputFile1.is_open()){
        string line;
        getline(inputFile1, line);
        cout << line << endl;
        istringstream(line) >> cpuatt1.cpu_name >> cpuatt1.user_time >> 
        cpuatt1.nice_time >> cpuatt1.system_kernel_time >> cpuatt1.idle_time >> cpuatt1.iowait_time >> 
        cpuatt1.irq_time >> cpuatt1.softirq_time;

        inputFile1.close();
    }
    else cout << "error not open" << endl;

        cout << "\nCPU at time T" << endl;
        cout <<  "cpu name: " << cpuatt.cpu_name << "\nuser_time: " << cpuatt.user_time <<
        "\nnice_time:" << cpuatt.nice_time << "\nsystem_kern_time:" << cpuatt.system_kernel_time << "\nidle_time: " <<
        cpuatt.idle_time << "\niowait_time: " << cpuatt.iowait_time << "\nirq_time: "
        << cpuatt.irq_time << "\nsoftirq_time: " << cpuatt.softirq_time << endl;

        cout << "\nCPU at time T1" << endl;
         cout <<  "cpu name: " << cpuatt1.cpu_name <<"\nuser_time: " <<  cpuatt1.user_time << "\nnice_time:" <<
        cpuatt1.nice_time << "\nsystem_kern_time:" << cpuatt1.system_kernel_time << "\nidle_time: " <<
        cpuatt1.idle_time << "\niowait_time: " << cpuatt1.iowait_time << "\nirq_time: "
        << cpuatt1.irq_time << "\nsoftirq_time: " << cpuatt1.softirq_time << endl;

        cout << "\ndifference" << endl;
        cout << "user_time: " << cpuatt1.user_time - cpuatt.user_time << "\nnice_time:" <<
        cpuatt1.nice_time - cpuatt.nice_time <<  "\nsystem_kern_time:" <<
        cpuatt1.system_kernel_time - cpuatt.system_kernel_time << "\nidle_time: " <<
        cpuatt1.idle_time - cpuatt.idle_time << "\niowait_time: " <<
        cpuatt1.iowait_time - cpuatt.iowait_time << "\nirq_time: " <<
        cpuatt1.irq_time - cpuatt.irq_time << "\nsoftirq_time: " <<
        cpuatt1.softirq_time - cpuatt.softirq_time << endl;
        
}