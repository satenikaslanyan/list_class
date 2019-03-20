all:  bin/out

CC := g++
SOURCES := $(wildcard src/*cpp)
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
INC := -I./inc
DEPENDS := $(patsubst src/%.cpp,obj/%.dep,$(SOURCES))

compiler_flags := -Wall -Wextra -pedantic -std=c++11 -c -g

ifeq ($(MAKECMDGOALS),)
	-include $(DEPENDS)
else ifeq ($(MAKECMDGOALS),all)
	-include $(DEPENDS)
endif


obj/%.dep : src/%.cpp
	mkdir -p obj
	$(CC) $(INC) -MM $< -MT "$@ $(patsubst %.dep,%.o,$@)" -o $@

obj/%.o :
	$(CC) $(compiler_flags) $(INC) $< -o $@ 

bin/out : $(OBJECTS) ./bin ./inc
	$(CC) $(OBJECTS) -o $@

./bin:
	mkdir -p bin

./inc:
	mkdir -p inc
	cp ./src/*.hpp ./inc/.

.PHONY clean: 
	rm -rf ./obj  ./bin ./inc




