/**
 * 
 * @file	LinList.cpp
 * @author	folz
 * @date	20.05.2012
 */

#include <iostream>
#include "LinList.h"


class leereException : public exception {
    virtual const char *what() const throw() {
        return "Leere Liste!";
    }
} leeresListeExp;

class stellenException : public exception {
    virtual const char *what() const throw() {
        return "Liste ist zu klein!";
    }
} stellenExp;

class outOfBoundsException : public exception {
    virtual const char *what() const throw() {
        return "Out of bounds!";
    }
} outOfBoundsExp;

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

LinList::LinList(const LinList &list) {
    this->size=0;
    this->first = nullptr;
    this->last = nullptr;
    for(int i = 1; i <= static_cast<int>(list.size); i++){
        this->insert(i, list.get(i)->getInhalt());
    }
}
void LinList::push_back(InhaltTyp t) {
	ListElement* tmp = new ListElement(t, this->get_End(),nullptr);
    if(this->size == 0) {
        this->first = tmp;
        this->last = tmp;
        this->size++;
    } else {
        this->get_End()->next = tmp;
        this->size++;
        this->last = tmp;
    }
}

void LinList::push_front(InhaltTyp t) {
	ListElement* tmp = new ListElement(t, nullptr, this->get_First());
    if(this->size == 0) {
        this->first = tmp;
        this->last = tmp;
        this->size++;
    } else {
        this->get_First()->previous = tmp;
        this->size++;
        this->first = tmp;
    }
}

void LinList::pop_back() {
    if(this->size < 1) {
        throw leeresListeExp;
    }
	this->size--;
	ListElement* newEnd = this->get_End()->previous;
	delete(this->get_End());
	this->last = newEnd;
    if(this->size >= 1) {
        this->last->next = nullptr;
    }
}

void LinList::pop_front() {
    if(this->size < 1) {
        throw leeresListeExp;
    }
	this->size--;
	ListElement* newFirst = this->get_First()->next;
	delete(this->get_First());
	this->first = newFirst;
    if(this->size >= 1) {
        this->first->previous = nullptr;
    }
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
        if(static_cast<size_t>(stelle) > this->size) {
            push_back(input);
        } else {
            if (this->size < 1) {
                push_front(input);
            } else {
                ListElement *tmp = this->first->next;
                for (int i = 2; i < stelle; i++) {
                    tmp = tmp->next;
                }
                ListElement *in = new ListElement(input, tmp->previous, tmp);
                tmp->previous->next = in;
                tmp->previous = in;
                this->size++;
            }
        }
    }
}

ListElement* LinList::get(int stelle) const {
    if(stelle > this->size || stelle  < 1 ){
        throw outOfBoundsExp;
    }
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

ListElement* LinList::operator[](int stelle) {
    return get(stelle);
}

void LinList::setFirst(ListElement *first) {
    this->first = first;
}

void LinList::setLast(ListElement *last) {
    this->last = last;
}

LinList& operator+(const LinList& liste, const LinList& zweite) {
    LinList* neue1 = new LinList(liste);
    LinList* neue2 = new LinList(zweite);
    neue1->last->setnext(neue2->get_First());
    //neue2->setFirst(neue1->get_End());
    neue2->first->setprev(neue1->get_End());
    neue1->setLast(neue2->get_End());
    //neue1->last = neue2->last;

    //neue2->first = neue1->first;
    neue1->size = liste.size + zweite.size;
    /*for(int i = 1; i <= static_cast<int>(zweite.size); i++) {
        neue1->push_back(zweite.get(i)->getInhalt());
    }*/
    return *neue1;
}

LinList& LinList::operator+=(LinList& liste) {
    this->last->next = liste.first;
    liste.first->previous = this->last;
    this->last = liste.last;
    return *this;
}

bool operator==(const LinList& liste, const LinList& zweite) {
    if(liste.size != zweite.size){
        return false;
    }
    for(size_t i = 1; i <= liste.size; i++) {
        if(liste.get(i)->getInhalt() != zweite.get(i)->getInhalt()) {
            return false;
        }
    }
    return true;
}

bool operator!=(const LinList& liste, const LinList& zweite) {
    return !(liste==zweite);
}

void LinList::erase(int stelle){
    if(this->size < 1){
        throw leeresListeExp;
    }
    if(static_cast<size_t>(stelle) > this->size) {
        throw stellenExp;
    }
    if(static_cast<size_t>(stelle) < 1){
        throw outOfBoundsExp;
    }
    if(stelle == 1) {
        pop_front();
    } else {
        if(stelle == this->size){
            pop_back();
        } else {
            ListElement* tmp = this->first;
            for(int i = 1; i < stelle; i++){
                tmp = tmp->next;
            }
            this->size--;
            tmp->previous->next= tmp->next;
            tmp->next->previous = tmp->previous;
            delete(tmp);
        }
    }

}

void LinList::clear() {
	delete this;
}


ostream& operator<<(ostream& stream, const LinList& liste) {
    stream << "Listenlaenge: " << liste.size << endl;
    for(int i = 1; i <= liste.size; i++){
        stream << "Element " << i << ": " << liste.get(i)->getInhalt() << endl;
    }
	return stream;
}

void LinList::check(bool x, exception e){
    if(x){
        throw e;
    }
}