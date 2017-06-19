/**
 * 
 * @file	ListElement.cpp
 * @author	folz
 * @date	20.05.2012
 */

#include "ListElement.h"


ListElement::ListElement(InhaltTyp inhalt, ListElement* previous,
		                                   ListElement* next) {
	this->inhalt = inhalt;
	this->previous = previous;
	this->next = next;
}

ListElement::ListElement(const ListElement &element) {

}

void ListElement::setprev(ListElement *prev) {
    this->previous=prev;
}

void ListElement::setnext(ListElement *next) {
    this->next = next;
}

ListElement *ListElement::getPrevious() const {
    return previous;
}

ListElement *ListElement::getNext() const {
    return next;
}

InhaltTyp ListElement::getInhalt() const{
    return this->inhalt;
}
ListElement::~ListElement() {
	// TODO Auto-generated destructor stub
}

