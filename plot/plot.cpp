
#include "plot.hpp"

Plot::Plot(std::string filepath) {
// open the given file
// TODO: add input restrictions (check for .dat or directroy existence or default to plot/data/)
    data.open(filepath);
}

void Plot::comment(std::string comment) {
  data << "# " << comment << std::endl;
}

void Plot::signalName(std::string name) {
  data << '"' << name << '"'  << std::endl;
}

void Plot::writeToFile(std::vector<float> sig, float idxstep, float idxoffset) {
    float idx = 0.0;
    for(unsigned int i = idxoffset/idxstep; i < sig.size(); i++) {
        data << idx << " " << sig[i] << std::endl;
        idx += idxstep;
    }
    data << "\n";
    data << "\n";
}

void Plot::writeToFile(float* sig, float idxstep, float idxoffset) {
    float idx = 0.0;
    for(unsigned int i = idxoffset/idxstep; i < size; i++) {
        data << idx << " " << sig[i] << std::endl;
        idx += idxstep;
    }
    data << "\n";
    data << "\n";
}

void Plot::writeToFile(double* sig, float idxstep, float idxoffset) {
    float idx = 0.0;
    for(unsigned int i = idxoffset/idxstep; i < size; i++) {
        data << idx << " " << sig[i] << std::endl;
        idx += idxstep;
    }
    data << "\n";
    data << "\n";
}

void Plot::close() {
    data.close();
}

void Plot::setSize(unsigned int size) {
    this->size = size;
}
