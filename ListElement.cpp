/**
 * 
 * @file	ListElement.cpp
 * @author	folz
 * @date	20.05.2012
 * mail@hendrik-haas.de
 * Partner: Julian Bruna
 */

#include "ListElement.h"

/**
 * default constructor
 * @param inhalt
 * @param previous
 * @param next
 */
ListElement::ListElement(InhaltTyp inhalt, ListElement* previous,
		                                   ListElement* next) {
	this->inhalt = inhalt;
	this->previous = previous;
	this->next = next;
}

/**
 * copy constructor
 * @param element
 */
ListElement::ListElement(const ListElement &element) {
    this->inhalt = element.getInhalt();
    this->previous = element.getPrevious();
    this->next = element.getNext();
}

/**
 * setter for operator
 * @param prev
 */
void ListElement::setprev(ListElement *prev) {
    this->previous=prev;
}

/**
 * setter for operator
 * @param next
 */
void ListElement::setnext(ListElement *next) {
    this->next = next;
}

/**
 * getter for operator
 * @return
 */
ListElement *ListElement::getPrevious() const {
    return previous;
}

/**
 * getter for operator
 * @return
 */
ListElement *ListElement::getNext() const {
    return next;
}

/**
 * getter for operator
 * @return
 */
InhaltTyp ListElement::getInhalt() const{
    return this->inhalt;
}

/**
 * destructor #no_new
 */
ListElement::~ListElement() {
	}

