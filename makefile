CC=gcc
CXX=g++
RM=rm -f
PR=lager
CPPFLAGS=-Wall -O2 -g -pedantic -std=c++14
SRCS=LinList.cpp LinListTst.cpp LinList.h ListDialog.cpp ListDialog.h ListElement.cpp ListElement.h
OBJS=$(subst .cc,.cpp,.h,.hh,.o,$(SRCS))
all: LinList
LinList: main.o LinList.o ListDialog.o ListElement.o 
	$(CXX) $(CPPFLAGS) -o linlist main.o LinList.o ListDialog.o ListElement.o
main.o: LinListTst.cpp
	$(CXX) $(CPPFLAGS) -c LinListTst.cpp
LinList.o: LinList.cpp LinList.h
	$(CXX) $(CPPFLAGS) -c LinList.cpp LinList.h
ListElement.o: ListElement.cpp ListElement.h
	$(CXX) $(CPPFLAGS) -c ListElement.cpp ListElement.h
ListDialog.o: ListDialog.cpp ListDialog.h
	$(CXX) $(CPPFLAGS) -c ListDialog.cpp ListDialog.h

.PHONY: clean
clean:
	$(RM) $(PR) *.o *.gch

.PHONY: clear
clear:
	$(RM) *.o *.gch