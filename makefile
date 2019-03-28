all:  bin/out

CC := g++
SOURCES := $(wildcard src/*cpp)
INCLUDEH := $(wildcard src/*hpp) 
INCLUDET := $(wildcard src/*tpp)
INCLUDE_H = $(patsubst src/%.hpp, inc/%.hpp, $(INCLUDEH))
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
INC := ./inc
DEPENDS := $(patsubst src/%.cpp,obj/%.dep,$(SOURCES))
CFLAGS := -c -g -Wall -Wextra -pedantic -std=c++11

ifeq ($(MAKECMDGOALS),)
	    -include $(DEPENDS)
else ifeq ($(MAKECMDGOALS), all)
	    -include $(DEPENDS)
endif

obj/%.dep : src/%.cpp
	mkdir -p obj
	$(CC) -I$(INC) -MM $< -MT "$@ $(patsubst %.dep,%.o,$@)" -o $@

obj/%.o :
	$(CC) $(CFLAGS) -I$(INC) $< -o $@ 

bin/out : $(OBJECTS) ./bin
	$(CC) $(OBJECTS) -o $@

./inc :
	mkdir -p inc

./bin :
	mkdir -p bin
	$(MAKE) $(INCLUDE_H)

inc/%hpp : src/%hpp ./inc
	ln $< $@

.PHONY clean: 
	rm -rf ./obj ./bin ./inc
