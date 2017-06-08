/**
 * 
 * @file	LinList.cpp
 * @author	folz
 * @date	20.05.2012
 */

#include "LinList.h"


LinList::LinList() {
	this->first = nullptr;
	this->last = nullptr;
	this->size = 0;
}

LinList::~LinList() {
	// TODO Auto-generated destructor stub
}

void LinList::push_back(InhaltTyp t) {
	ListElement* tmp = new ListElement(t, this->get_End(),nullptr);
	this->size++;
	this->last = tmp;
}

void LinList::push_front(InhaltTyp t) {
	ListElement* tmp = new ListElement(t, nullptr, this->get_First());
	this->size--;
	this->first = tmp;
}

void LinList::pop_back() {
	this->size--;
	ListElement* newEnd = this->get_End()->previous;
	delete(this->get_End());
	this->last = newEnd;
	this->last->next= nullptr;
}

void LinList::pop_front() {
}

ListElement* LinList::get_End() const {
	return this->last;
}

ListElement* LinList::get_First() const {
	return this->first;
}


