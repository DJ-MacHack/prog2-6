/**
 * 
 * @file	ListElement.h
 * @author	folz
 * @date	20.05.2012
 * mail@hendrik-haas.de
 * Partner: Julian Bruna
 */

#ifndef LISTELEMENT_H_
#define LISTELEMENT_H_
#include <string>
using namespace std;
typedef string InhaltTyp;


/**
 * Listenelement fuer eine doppelt-verkettete Lineare Liste
 * 
 * @author	folz
 * @version 
 * @date	20.05.2012
 */
class ListElement {
    friend class LinList;
    friend class ListDialog;
public:
	ListElement(InhaltTyp, ListElement* front, ListElement* next);
    ListElement(const ListElement& element);
	~ListElement();
    void setprev(ListElement* prev);
    void setnext(ListElement* next);
    InhaltTyp getInhalt() const;

    ListElement *getPrevious() const;

    ListElement *getNext() const;

private:
	InhaltTyp inhalt;
	ListElement* previous;
	ListElement* next;
};

#endif /* LISTELEMENT_H_ */
