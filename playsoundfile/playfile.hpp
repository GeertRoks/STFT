#ifndef PLAYFILE_H
#define PLAYFILE_H

#include <string>
#include <array>
#include <iostream>
#include <sndfile.hh>

#define MAXNUMOFCHANNELS 2
typedef struct File {
    float* mono;
    float* left;
    float* right;
    unsigned int size;
}File;

class Playfile {
    public:
        Playfile();
        Playfile(std::string file);
        ~Playfile();

        void setFile(std::string file);

        float* getSamples();
        float* getSamples(const unsigned int num_samples, unsigned int offset = 0);
        float getSample(unsigned int index);
        void getSamples(float* input_arr, unsigned int num_samples);
        unsigned int getSize();

    private:
       int selectedSample;
        const float **samples = new const float*[6];
        SNDFILE* infile = NULL;
        SF_INFO sfinfo;
        File file;
};

#endif
