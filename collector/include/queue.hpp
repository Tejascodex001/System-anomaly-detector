#ifndef SAMPLE_QUEUE_HPP
#define SAMPLE_QUEUE_HPP

#include <atomic>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <sampler.hpp>

class Samplequeue{
    private:
        std::mutex mutex_;
        std::condition_variable cond_;
        std::queue<sample> queue_;

    public:
        void push(const sample &s);
        sample pop(const std::atomic<bool> &stop);
        bool empty();
        void notifyall();
};

#endif