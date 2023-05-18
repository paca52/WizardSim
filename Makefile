CC = g++
FLAGS = -O1 -Wall -std=c++20 -Wno-missing-braces -Iinclude/ -Llib/ -lraylib -lopengl32 -lgdi32 -lwinmm -static-libstdc++ -static-libgcc -static -MP -MD
BIN = game

SRC = main.cpp $(wildcard src/*.cpp)

tmp = $(wildcard src/*.cpp)
OBJ = obj/main.o $(patsubst src/%.cpp, obj/%.o, $(tmp))
DEPFILES = obj/main.d $(patsubst src/%.cpp, obj/%.d, $(tmp))

all: $(BIN)
	.\$(BIN).exe

$(BIN): $(OBJ)
	$(CC) $^ -o $@ $(FLAGS)

obj/main.o: main.cpp
	$(CC) -c $< -o $@ $(FLAGS)

obj/%.o: src/%.cpp
	$(CC) -c $< -o $@ $(FLAGS)

clean:
	-del $(BIN).exe $(patsubst obj/%, obj\\%, $(OBJ)) $(patsubst obj/%, obj\\%, $(DEPFILES))

clean_obj:
	-del $(patsubst obj/%, obj\%, $(OBJ)) $(patsubst obj/%, obj\\%, $(DEPFILES))

-include $(DEPFILES)
