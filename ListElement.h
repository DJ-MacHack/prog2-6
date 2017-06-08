/**
 * 
 * @file	ListElement.h
 * @author	folz
 * @date	20.05.2012
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
public:
	ListElement(InhaltTyp, ListElement* =0, ListElement* =0);
	~ListElement();
	friend class LinList;
private:
	InhaltTyp inhalt;
	ListElement* previous;
	ListElement* next;
};

#endif /* LISTELEMENT_H_ */
