SRCS=$(shell ls *.cpp)
OBJS=$(addsuffix .o, $(basename $(SRCS)))
LPATH=/usr/include/jsoncpp
a:$(OBJS)
	echo $(OBJS)
clean:
	-rm -rf *.o
%.o:%.cpp
	g++ -g -o $@ $< -lcurl -ljsoncpp -I$(LPATH)

