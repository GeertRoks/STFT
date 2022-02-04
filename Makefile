PRGRM = stft
OBJ = main.o

CXXFLAGS := -Wall -std=c++17
CXXFLAGS +=
LDFLAGS = -lkfr_dft -lkfr_io
LDLIBS = -I/usr/include/kfr/

all: $(PRGRM)

# link the program
$(PRGRM): $(OBJ)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS)

# builds given .o files dependend on their corresponding .cpp and .h files
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm $(OBJ)
	rm $(PRGRM)

.PHONY: all clean

