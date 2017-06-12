/**
 * 
 * @file	LinList.cpp
 * @author	folz
 * @date	20.05.2012
 */

#include "LinList.h"


class LeereException : public exception {
    virtual const char *what() const throw() {
        return "Leere Liste!";
    }
} leeresListeExp;

class stellenException : public exception {
    virtual const char *what() const throw() {
        return "Liste ist zu klein!";
    }
} stellenExp;

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
    check(this->size < 1, leeresListeExp);
	this->size--;
	ListElement* newEnd = this->get_End()->previous;
	delete(this->get_End());
	this->last = newEnd;
	this->last->next= nullptr;
}

void LinList::pop_front() {
    check(this->size < 1, leeresListeExp);
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
    if(stelle == 1){
        push_front(input);
    } else {
        ListElement* tmp = this->first->next;
        for(int i = 2; i < stelle; i++){
            tmp = tmp->next;
        }
        ListElement* in = new ListElement(input, tmp->previous, tmp);
        tmp->previous->next = in;
        tmp->previous = in;
        this->size++;
    }
}

ListElement* LinList::get(int stelle) const {
    if(stelle==1){
        return this->first;
    }
    if(stelle == static_cast<int>(this->size)) {
        return this->last;
    }
    ListElement* tmp = this->first->next;
    for(int i = 2; i < stelle; i++){
        tmp = tmp->next;
    }
    return tmp;
}

void LinList::erase(int stelle){
    check(static_cast<size_t>(stelle) > this->size, stellenExp);
    ListElement* tmp = this->first;
    for(int i = 1; i < stelle; i++){
        tmp = tmp->next;
    }
    this->size--;
    tmp->previous->next= tmp->next;
    tmp->next->previous = tmp->previous;
    delete(tmp);

}

void LinList::clear() {
	delete this;
}


ostream& operator<<(ostream& stream, const LinList&) {
	return stream;
}

void LinList::check(bool x, exception e){
    if(x){
        throw e;
    }
}