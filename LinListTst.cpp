/**
 * 
 * @file	LinListTst.cpp
 * @author	folz
 * @date	21.05.2012
 * mail@hendrik-haas.de
 * Partner: Julian Bruna
 */

#include <iostream>
#include "LinList.h"
#include "ListDialog.h"
using namespace std;

/**
 * default main
 * @return
 */
int main() {
	LinList liste1;
	liste1.push_back("alpha");
	liste1.push_back("beta");
    cout << liste1 << endl;
    cout << "Standardtest fertig - Dialog geoeffnet." << endl;
    ListDialog dialog;
    dialog.start();
    delete &liste1;
}



