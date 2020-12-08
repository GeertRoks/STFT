#include <iostream>
#include <fftw3.h>
#include "playsoundfile/playfile.hpp"
#include "plot/plot.hpp"

int main() {

    Playfile file("flute-c4.wav");
    Plot plot("flute-c4.dat");

    double *in;
    double *X_mag, *X_phase;
    fftw_complex *out;
    fftw_plan p;
    unsigned int M = 511;
    unsigned int N = 512;
    unsigned int offset = 44100;

    in = (double*) fftw_malloc(sizeof(double) * N);
    X_mag = (double*) fftw_malloc(sizeof(double) * N);
    X_phase = (double*) fftw_malloc(sizeof(double) * N);

    for (unsigned int i = 0; i < M; i++) {
        in[i] = static_cast<double>(file.getSample(i + offset));
    }

    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);

    fftw_execute(p);

    for (unsigned int i = 0; i < N; i++) {
        X_mag[i] = out[i][0];
        X_phase[i] = out[i][1];
    }

    for (unsigned int i = 0; i < N; i++) {
        std::cout << i << ": " << out[i][0] << ", " << out[i][1] << std::endl;
    }

    plot.setSize(N);
    plot.signalName("Audio signal");
    plot.writeToFile(in);

    plot.signalName("FFT");
    plot.writeToFile(X_phase);

    fftw_destroy_plan(p);
    fftw_free(in);
    fftw_free(out);

    return 0;
}
