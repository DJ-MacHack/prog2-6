/**
* @file: ListDialog.h
* @author:DJ MacHack
* @date: 12.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#ifndef LINLIST_LISTDIALOG_H
#define LINLIST_LISTDIALOG_H


#include <vector>
#include "LinList.h"
enum FunktionsTyp {LISTE_ANLEGEN, ELEMENT_EINFUEGEN, LISTE_KOPIEREN, ELEMENT_KOPIEREN, LISTE_LOESCHEN,
        ELEMENT_LOESCHEN, LISTEN_ADDIEREN, ENDE = 9};
class ListDialog {
public:
    ListDialog();
    ListDialog(LinList* list);
    void start();
    FunktionsTyp einlesenFunktion();
    void ausfuehrenFunktion(FunktionsTyp funktion);
    void vecout();
    virtual ~ListDialog();


private:
    std::vector<LinList*> vec;
    int listcount = 0;

};


#endif //LINLIST_LISTDIALOG_H
