CC=gcc
CXX=g++
RM=rm -f
PR=lager
CPPFLAGS=-Wall -O2 -g -pedantic -std=c++14
SRCS=LinList.cpp LinListTst.cpp ListDialog.cpp ListElement.cpp
OBJS=$(subst .cc,.cpp,.h,.hh,.o,$(SRCS))
all: LinList
LinList: LinListTst.o LinList.o ListDialog.o ListElement.o 
	$(CXX) $(CPPFLAGS) -o linlist LinListTst.o LinList.o ListDialog.o ListElement.o
LinListTst.o: LinListTst.cpp
	$(CXX) $(CPPFLAGS) -c LinListTst.cpp
LinList.o: LinList.cpp LinList.h
	$(CXX) $(CPPFLAGS) -c LinList.cpp
ListElement.o: ListElement.cpp
	$(CXX) $(CPPFLAGS) -c ListElement.cpp
ListDialog.o: ListDialog.cpp ListDialog.h
	$(CXX) $(CPPFLAGS) -c ListDialog.cpp

.PHONY: clean
clean:
	$(RM) $(PR) *.o *.gch

.PHONY: clear
clear:
	$(RM) *.o *.gch