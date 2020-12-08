
#ifndef PLOT_HPP
#define PLOT_HPP

#include <fstream>
#include <string>
#include <vector>

class Plot {
public:
    Plot(std::string filepath);

    void comment(std::string comment);
    void signalName(std::string name);
    void writeToFile(std::vector<float> sig, float idxstep = 1.0, float idxoffset = 0.0);
    void writeToFile(float* sig, float idxstep = 1.0, float idxoffset = 0.0);
    void writeToFile(double* sig, float idxstep = 1.0, float idxoffset = 0.0);
    void setSize(unsigned int size);
    void close();

private:
    std::ofstream data;
    unsigned int size = 441000;

};

#endif //PLOT_HPP
