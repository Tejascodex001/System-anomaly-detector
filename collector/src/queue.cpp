#include "queue.hpp"
#include "sampler.hpp"
#include <mutex>


using namespace std;

void Samplequeue::push(const sample &s){
    {
    lock_guard<mutex> lock(mutex_);
    queue_.push(s);
    }
    cond_.notify_one();
}

sample Samplequeue::pop(){
    unique_lock<mutex> lock(mutex_);
    cond_.wait(lock, [&] { return !queue_.empty(); });
    sample s = queue_.front();
    queue_.pop();
    return s;
}