/**
 * 
 * @file	LinList.h
 * @author	folz
 * @date	20.05.2012
 */

#ifndef LINLIST_H_
#define LINLIST_H_
#include "ListElement.h"

/**
 * Doppelt-verkettete Lineare Liste
 * 
 * @author	folz
 * @version 
 * @date	20.05.2012
 */
class LinList {
public:
	LinList();
	~LinList();
	void push_back (InhaltTyp t);
	void push_front(InhaltTyp t);
	void pop_back();
	void pop_front();
	friend ostream& operator<< (ostream&, const LinList&);
private:
	size_t size;
	ListElement* first;
	ListElement* last;
};

#endif /* LINLIST_H_ */
