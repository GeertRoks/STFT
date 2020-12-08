
#include "playfile.hpp"

Playfile::Playfile() {
}

Playfile::Playfile(std::string file) {
    setFile(file);
}

Playfile::~Playfile() {
//    file_sub_array = NULL;
//    delete file_sub_array[];
//    file.mono = NULL;
//    file.left = NULL;
//    file.right = NULL;
//    delete file.mono[];
//    delete file.left[];
//    delete file.right[];
}


void Playfile::setFile(std::string filepath) {
    //	TODO: Add path redirection to project folder
    //	std::string path = "projects/PROJECT_NAME/" + filepath;
    if((this->infile = sf_open(filepath.c_str(), SFM_READ, &sfinfo)) == NULL){
        std::cout << "File read error\n";
        exit(1);
    }
    if(sfinfo.channels > MAXNUMOFCHANNELS) {
        std::cout << "File contains too many channels\n";
        exit(1);
    }
    float* readfile = new float[sfinfo.frames * sfinfo.channels];
    int num = sf_read_float(infile,readfile,sfinfo.frames * sfinfo.channels);
    sf_close(infile);

    this->file.size = sfinfo.frames;
    this->file.mono = new float[sfinfo.frames];

    if (sfinfo.channels > 1) {
        int j = 0;
        this->file.left = new float[file.size];
        this->file.right = new float[file.size];
        for (auto i = 0; i < num; i += sfinfo.channels) {
            //Make mono by skipping the right channel
            //TODO: Sum left and right
            this->file.left[j] = readfile[i];
            this->file.right[j] = readfile[i+1];
            this->file.mono[j] = (readfile[i] + readfile[i+1]) * 0.5;
            j++;
        }
    } else {
        for (auto i = 0; i < num; i++) {
            this->file.mono[i] = readfile[i];
        }
    }
}

float* Playfile::getSamples() {
    return this->file.mono;
}

float* Playfile::getSamples(const unsigned int num_samples, unsigned int offset) {
    if (num_samples > file.size) {
        return this->file.mono;
    } else {
        float* file_sub_array = new float[num_samples];
        for(unsigned int i = 0; i < num_samples; i++) {
            file_sub_array[i] = file.mono[i + offset];
        }
        return file_sub_array;
    }
}

void Playfile::getSamples(float* input_arr, unsigned int num_samples) {
    for(unsigned int i = 0; i < num_samples; i++) {
        input_arr[i] = file.mono[i];
    }
}

float Playfile::getSample(unsigned int index) {
    return this->file.mono[index];
}

unsigned int Playfile::getSize() {
    return this->file.size;
};
