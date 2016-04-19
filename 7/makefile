CPPFILES = 4.cpp
FLAGS = -std=c++11 -pedantic -Wall -g -lm -lpthread  -O2
EXE = main
CC = g++
all: $(EXE)
$(EXE): $(CPPFILES)
	$(CC) $(FLAGS) -o $(EXE) $(CPPFILES)
clear:
	rm -rf $(EXE) *.o input output *.tmp *.temp file *.out *.in
	rm -rf test.cpp
	rm -rf $(EXE1) $(EXE2) $(EXE3) $(EXE4)

CPP1 = 1.cpp
EXE1 = 1.out
c1: $(EXE1)
$(EXE1): $(CPP1)
	$(CC) $(FLAGS) -o $(EXE1) $(CPP1)

CPP2 = 2.cpp
EXE2 = 2.out
c2: $(EXE2)
$(EXE2): $(CPP2)
	$(CC) $(FLAGS) -o $(EXE2) $(CPP2)

CPP3 = 3.cpp
EXE3 = 3.out
c3: $(EXE3)
$(EXE3): $(CPP3)
	$(CC) $(FLAGS) -o $(EXE3) $(CPP3)

CPP4 = 4.cpp
EXE4 = 4.out
c4: $(EXE4)
$(EXE4): $(CPP4)
	$(CC) $(FLAGS) -o $(EXE4) $(CPP4)
CPP5 = 5.cpp
EXE5 = 5.out
c5: $(EXE5)
$(EXE5): $(CPP5)
	$(CC) $(FLAGS) -o $(EXE5) $(CPP5)
CPP6 = 6.cpp
EXE6 = 6.out
c6: $(EXE6)
$(EXE6): $(CPP6)
	$(CC) $(FLAGS) -o $(EXE4) $(CPP6)
CPP7 = 7.cpp
EXE7 = 7.out
c7: $(EXE7)
$(EXE7): $(CPP7)
	$(CC) $(FLAGS) -o $(EXE7) $(CPP7)
CPP8 = 8.cpp
EXE8 = 8.out
c8: $(EXE8)
$(EXE8): $(CPP8)
	$(CC) $(FLAGS) -o $(EXE8) $(CPP8)
CPP9 = 9.cpp
EXE9 = 9.out
c9: $(EXE9)
$(EXE9): $(CPP9)
	$(CC) $(FLAGS) -o $(EXE9) $(CPP9)
TESTCPP = test.cpp
TESTEXE = test.out
test: $(TESTEXE)
$(TESTEXE): $(TESTCPP)
	$(CC) $(FLAGS) -o $(TESTEXE) $(TESTCPP)
