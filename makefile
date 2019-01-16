# Project 2: Zoo Tycoon
# Author: Melisa Lee
# Date: 10/21/2018
# Referenced make file lecture

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3LDFLAGS = -lboost_date_time
LDFLAGS = -lboost_date_time

HEADER = Zoo.hpp Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp validate.hpp

OBJS = zooTycoonMain.o Zoo.o Animal.o Tiger.o Penguin.o Turtle.o validate.o

RCS = zooTycoonMain.cpp Zoo.cpp Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp validate.cpp

Lab1: ${OBJS} ${HEADER}
	${CXX} ${LDFLAGS} ${OBJS} -o Project2
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *o Project2
