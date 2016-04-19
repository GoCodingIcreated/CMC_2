CPPFILES = 4.cpp
CC = g++
FLAGS = -std=c++11 -Wall -Werror -Wformat-security -Wignored-qualifiers -Winit-self -Wswitch-default -Wfloat-equal -Wshadow -Wpointer-arith -Wtype-limits -Wempty-body -Wlogical-op -Wmissing-field-initializers -Wctor-dtor-privacy -Wnon-virtual-dtor -Wstrict-null-sentinel -Wold-style-cast -Woverloaded-virtual -Wsign-promo -std=gnu++11
EXE = main
all: $(EXE)
$(EXE): $(CPPFILES)
	$(CC) -o $(EXE) $(CPPFILES) $(FLAGS)
clear:
	rm -rf *.o $(EXE) *.out *.in *.temp *.tmp input? output? file?
	rm test?.cpp
