#include "queue.hpp"
#include "sampler.hpp"
#include <atomic>
#include <mutex>


using namespace std;

void Samplequeue::push(const sample &s){
    {
    lock_guard<mutex> lock(mutex_);
    queue_.push(s);
    }
    cond_.notify_one();
}

sample Samplequeue::pop(const std::atomic<bool> &stop){
    unique_lock<mutex> lock(mutex_);
    cond_.wait(lock, [&] { return !queue_.empty() || stop.load(); });
    if (queue_.empty()) return {};
    sample s = queue_.front();
    queue_.pop();
    return s;
}

bool Samplequeue::empty(){
    unique_lock<mutex> lock(mutex_);
    return queue_.empty();
}

void Samplequeue::notifyall(){
    cond_.notify_all();
}