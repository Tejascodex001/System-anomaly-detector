#include "sampler.hpp"
#include "writer.hpp"
#include "queue.hpp"
#include <functional>
#include <thread>
#include <iostream>

using namespace std;

void write(Samplequeue &q){
    Writer writer("sample.csv");
    std::cout << "writer is working" << endl;
    while(true){
        sample data = q.pop();
        writer.write_sample(data);
        writer.flush();
    }
}

int main (){  
    Samplequeue samplequeue;
    thread t(write, ref(samplequeue));
    cout << "main is working" << endl;
    while(true){
        sample data = sample_usage();
        cout << "main while loop" << endl;
        samplequeue.push(data);
        cout << "pushed" << endl;
    }
}