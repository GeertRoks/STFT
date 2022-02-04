
#include <iostream>

#include <kfr/all.hpp>

#define KFR_DFT_MULTI 0

int main() {

    std::cout << "Hello stft" << std::endl;

    // Open file as sequence of float`s, conversion is performed internally
    kfr::audio_reader_wav<double> reader(kfr::open_file_for_reading("flute-c4.wav"));
    kfr::univector2d<double> audio = reader.read_channels();

    plot_show("Flute c4", audio[0], "title='name', div_by_N=True");

    kfr::dft_plan_real<double> plan(1024);
    kfr::univector<double, 1024> in;
    kfr::univector<kfr::complex<double>,1024> out;
    for (unsigned int i = 0; i < 1024; i++) {
        in[i] = audio[0][i];
    }


    kfr::univector<kfr::u8> temp(plan.temp_size);
    plan.execute(out, in, temp);


    return 0;
}
