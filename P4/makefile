GXX = g++
FLAGS = -std=c++11
OBJ = obj
SRC = src
INCLUDE = include
BIN = bin

all: bin

tablero.o:
	$(GXX) $(SRC)/tablero.cpp $(FLAGS) -c -I $(INCLUDE) -o $(OBJ)/tablero.o

caballo.o:
	$(GXX) $(SRC)/caballo.cpp $(FLAGS) -c -I $(INCLUDE) -o $(OBJ)/caballo.o

bin: tablero.o caballo.o
	$(GXX) $(OBJ)/tablero.o $(OBJ)/caballo.o -o $(BIN)/caballo $(FLAGS)

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/caballo
