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
	size_t tmp = this->size;
	for(size_t i = 0; i < tmp; i++){
		pop_front();
	}
}

void LinList::push_back(InhaltTyp t) {
	ListElement* tmp = new ListElement(t, this->get_End(),nullptr);
	this->get_End()->next = tmp;
	this->size++;
	this->last = tmp;
}

void LinList::push_front(InhaltTyp t) {
	ListElement* tmp = new ListElement(t, nullptr, this->get_First());
	this->get_First()->previous = tmp;
	this->size++;
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
	this->size--;
	ListElement* newFirst = this->get_First()->next;
	delete(this->get_First());
	this->first = newFirst;
	this->first->previous= nullptr;
}

ListElement* LinList::get_End() const {
	return this->last;
}

ListElement* LinList::get_First() const {
	return this->first;
}

void LinList::insert(int stelle, InhaltTyp input){

}

void LinList::erase(int stelle){

}

void LinList::clear() {
	delete this;
}


ostream& LinList::operator<<(ostream & stream, const LinList &) {
	return stream;
}
