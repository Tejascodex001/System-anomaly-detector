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

void writer_thread(Samplequeue &q){
    Writer writer("sample.csv");
    while(true){
        if(stop_request and q.empty()) break;
        sample data = q.pop(stop_request);
        if(stop_request && q.empty()) continue;
        writer.write_sample(data);
    }
    writer.flush();
    writer.close();
}
/*  Sigint handled completely ( I didnt learn much as this concept is difficult and i am burned)
    --Date: 10 Jan 2026.
*/
int main (){  
    std::signal(SIGINT, handle_sigint);
    Samplequeue samplequeue;
    thread t(writer_thread, ref(samplequeue));

    while(!stop_request){
        sample data = sample_usage();
        samplequeue.push(data);
    }
    samplequeue.notifyall();
    t.join();
}