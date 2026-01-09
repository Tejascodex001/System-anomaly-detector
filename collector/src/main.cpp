#include "sampler.hpp"
#include "writer.hpp"
#include "queue.hpp"
#include <functional>
#include <thread>
#include <csignal>
#include <atomic>

using namespace std;

std::atomic<bool> stop_request(false);

void handle_sigint(int){
    stop_request.store(true);
}

void write(Samplequeue &q){
    Writer writer("sample.csv");
    while(true){
        if(stop_request and q.empty()) break;
        sample data = q.pop();
        writer.write_sample(data);
    }
}
/*  basic sigint handling. (Phase 4.4: graceful shutdown wiring (queue + signal + thread join))
    --Date: 9 Jan 2026.
*/
int main (){  
    std::signal(SIGINT, handle_sigint);
    Samplequeue samplequeue;
    thread t(write, ref(samplequeue));

    while(!stop_request){
        sample data = sample_usage();
        samplequeue.push(data);
    }
    samplequeue.notifyall();
    t.join();
}