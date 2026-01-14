#include "writer.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

Writer::Writer(const string &Filename):header_written_(false){
    file_.open(Filename, ios::app);
    if (!file_.is_open()){
        cerr << "cannot open file" << endl;
        exit(1);
    }
    file_.seekp(0, ios::end);
    if (file_.tellp() == 0){
        file_ << "timestamp,cpu_usage,memory_usage,cpu_mean,mem_mean,cpu_std,mem_std,cpu_z,mem_z,anomaly_score\n";
        header_written_ = true;
    }
}

void Writer::write_sample(const sample &usage){
    file_ << usage.timeStamp << "," << usage.cpu_usage << "," << usage.mem_usage << "," << usage.cpu_mean << 
    "," << usage.mem_mean << "," << usage.cpu_std << "," << usage.mem_std << "," << usage.cpu_z << "," << usage.mem_z << 
    "," << usage.anomaly_score << "\n";
}

void Writer::close(){
    if (file_.is_open()) file_.close();
}

void Writer::flush(){
    if (file_.is_open()) file_.flush();
}