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

ListElement::~ListElement() {
	// TODO Auto-generated destructor stub
}

