exe_file = wumpus.out
CC = g++ -std=c++11 
OBJ = main.o arrow.o events.o grid.o
SRC = $(OBJ:%.o=%.cpp)
HEADER = $(OBJ:%.o=%.hpp)

$(exe_file): $(SRC) $(HEADER)
		$(CC) -o $(exe_file) $(SRC)

main.hpp:

clean:
		rm -f *.out *.o $(exe_file)