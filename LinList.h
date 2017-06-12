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
    LinList(const LinList& list);
	~LinList();
	void push_back (InhaltTyp t);
	void push_front(InhaltTyp t);
	void pop_back();
	void pop_front();
	ListElement* get_End() const;
	ListElement* get_First() const;
    ListElement* get(int stelle) const;
	friend ostream& operator<< (ostream& stream, const LinList&);
    void insert(int stelle, InhaltTyp input);
    void erase(int stelle);
    void clear();
private:
	size_t size;
    void check(bool x, exception e);
	ListElement* first;
	ListElement* last;
};

#endif /* LINLIST_H_ */
