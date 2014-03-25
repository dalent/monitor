SRCS=$(wildcard *.cpp)
OBJS=$(addsuffix .o, $(basename $(SRCS)))
LPATH=/usr/include/jsoncpp
a:$(OBJS)
	echo $(OBJS)
%.o:%.cpp
	g++ -g -o $@ $< -lcurl -ljsoncpp -I$(LPATH)

