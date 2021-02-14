
CC=g++

BUILD_DIR=build
OUTPUT=$(BUILD_DIR)/output/run
TEST_BUILD_DIR=$(BUILD_DIR)
TEST_OUTPUT=$(TEST_BUILD_DIR)/output/testRunner

SRC_DIR=src
TEST_DIR=test

_DEPS = Node.hpp Edge.hpp Dijkstra.hpp Reader.hpp Graph.hpp Parser.hpp

_OBJ = Node.o Edge.o Dijkstra.o Reader.o Graph.o Parser.o

_TEST = testCatch.o testNode.o testEdge.o testDijkstra.o testReader.o testGraph.o testParser.o



DEPS = $(patsubst %,$(SRC_DIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(BUILD_DIR)/%,$(_OBJ))
TEST = $(patsubst %,$(TEST_BUILD_DIR)/%,$(_TEST))

LIB_DIR=lib

CFLAGS=-I$(SRC_DIR) -I$(LIB_DIR)

TEST_LIBS = -lcatch -lstdc++fs


.PHONY: all clean build test

all: test

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ) $(BUILD_DIR)/main.o
	$(CC) -o $(OUTPUT) $^ $(CFLAGS)

$(TEST_BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

build-test: build $(TEST)
	$(CC) $(CFLAGS) -L$(LIB_DIR) -Wl,-rpath=${CURDIR}/$(LIB_DIR) -Wall -o $(TEST_OUTPUT) $(OBJ) $(TEST) $(TEST_LIBS)

test: build-test
	$(TEST_OUTPUT)

clean:
	rm -f $(BUILD_DIR)/*.o $(TEST_BUILD_DIR)/*.o $(OUTPUT) $(TEST_OUTPUT)







#g++ -I./ -L./ -Wl,-rpath=./ -Wall -o testCatch testCatch.cpp -lcatch
#-Wl,-rpath=./
