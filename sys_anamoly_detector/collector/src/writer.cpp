#include "writer.hpp"
#include "sampler.hpp"
#include <fstream>
#include <iostream>

int main(){
    std::string Filename = "test.csv";
    Writer Writer(Filename);
   sample Sample;
   Sample.cpu_usage = 1.1;
   
}