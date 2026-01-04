#include <iostream>

#include "proc_reader.hpp"
#include "sampler.hpp"

using namespace std;

int main (){  
    while (true){
    sample usage = sample_usage(); 
    cout << "cpu usage: " << usage.cpu_usage*100 << "%" << " timestamp: " << usage.timeStamp << endl;
    }  
}