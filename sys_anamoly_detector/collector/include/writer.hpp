#ifndef WRITER_HPP
#define WRITER_HPP

#include <fstream>
#include <string>

#include "sampler.hpp"

class Writer{
    public:
    Writer(const std::string &Filename);
    void write_sample(sample &Sample);
    void close();

    private:
    std::ofstream file_;
    bool header_written_;
};

#endif