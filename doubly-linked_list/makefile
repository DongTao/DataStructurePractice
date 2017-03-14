EXE = unittest
CXX = g++

GTEST_DIR = /home/docker/gtest

CFLAGS := --std=c++11 -g
INC_PATH := $(GTEST_DIR)
LIB_PATH := $(GTEST_DIR)
LIBS := gtest gtest_main pthread

SRC = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRC))

%.o : %.cpp *.h
	$(CXX) -c $< $(addprefix -I,$(INC_PATH)) $(CFLAGS) -o $@

all : $(OBJS)
	$(CXX) $(OBJS) $(addprefix -L,$(LIB_PATH)) $(addprefix -l,$(LIBS)) -o $(EXE)

.PHONY : clean
clean:
	rm -rf $(OBJS) $(EXE)
