/**
 * 
 * @file	LinListTst.cpp
 * @author	folz
 * @date	21.05.2012
 */
#include <iostream>
using namespace std;

#include "LinList.h"

int main() {
	LinList liste1;
	liste1.push_back("alpha");
	liste1.push_back("beta");
	cout << liste1 << endl;
}



