#ifndef SAMPLE_QUEUE_HPP
#define SAMPLE_QUEUE_HPP

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
        sample pop();
};

#endif