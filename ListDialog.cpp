/**
* @file: ListDialog.cpp
* @author:DJ MacHack
* @date: 12.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
* Partner: Julian Bruna
*/


#include <iostream>
#include "ListDialog.h"

/**
 * destructor
 */
ListDialog::~ListDialog() {
    for(int i = 0; i < this->vec.size(); i++){
        delete(this->vec.at(i));
    }
}

/**
 * constructor
 */
ListDialog::ListDialog() {
    this->vec.push_back(new LinList());
    this->listcount++;
    cout << "Neue Liste im Vector an Stelle " << this->listcount-1 << endl;
}

/**
 * dialog
 * @param list
 */
ListDialog::ListDialog(LinList *list) {
    this->vec.push_back(list);
    this->listcount++;
    cout << "Neue Liste im Vector an Stelle " << this->listcount-1 << endl;
}

/**
 * main dialog function
 */
void ListDialog::start() {
    FunktionsTyp funktion;
    do {
        try {
            funktion = einlesenFunktion();
            ausfuehrenFunktion(funktion);
        } catch (const string &e) {
            cout << "Ausnahme: " << e << endl;
        } catch (exception& e) {
            cout << e.what() << endl;
        }
        catch (...) {
            cout << "Unbekannter Fehler Ausfuehren!" << endl;
        }
        if(funktion == LISTE_LOESCHEN){
            break;
        }
    } while (funktion != ENDE);

}

/**
 * reads input of your choice
 * @return
 */
FunktionsTyp ListDialog::einlesenFunktion() {
    cout << LISTE_ANLEGEN << ": Liste anlegen; "
         << ELEMENT_EINFUEGEN << ": Element in die Liste einfuegen; "
         << ELEMENT_LOESCHEN << ": Element aus der Liste loeschen; "
         << LISTE_KOPIEREN << ": Liste kopieren; "
         <<  ELEMENT_KOPIEREN << ": Element kopieren; "
         << LISTE_LOESCHEN << ": Liste loeschen; "
         << LISTEN_ADDIEREN << ": Listen addieren; "
         << ENDE << ": beenden -> ";
    int funktion;
    if (cin) {
        cin >> funktion;
        cout << endl;
        return static_cast<FunktionsTyp>(funktion);
    } else {
        cout << "cin error" << endl;
        return ENDE;
    }
}

/**
 * executes functions
 * @param funktion
 */
void ListDialog::ausfuehrenFunktion(FunktionsTyp funktion) {
    std::string inhalt = "";
    int n, m, p, q;
    LinList r;
    switch (funktion) {
        case LISTE_ANLEGEN:
            this->vec.push_back(new LinList());
            this->listcount++;
            cout << "Neue Liste im Vector an Stelle " << this->listcount-1 << endl;
            vecout();
            break;
        case ELEMENT_EINFUEGEN:
            cout << "Listennummer (0 bis n): ";
            cin >> n;
            cout << endl;
            cout << "Listenposition (1 bis n): ";
            cin >> m;
            cout << endl;
            cout << "Inhalt: ";
            cin >> inhalt;
            cout << endl;
            this->vec.at(n)->insert(m, inhalt);
            cout << "Element eingefuegt!" << endl;
            vecout();
            break;
        case ELEMENT_KOPIEREN:
            cout << "Listennummer aus der kopiert wird (0 bis n): ";
            cin >> n;
            cout << endl;
            cout << "Listenposition des Elements das kopiert wird (1 bis n): ";
            cin >> m;
            cout << endl;
            cout << "Listennummer in die kopiert wird (0 bis n): ";
            cin >> p;
            cout << endl;
            cout << "Listenposition des Elements das kopiert wird (1 bis n): ";
            cin >> q;
            cout << endl;
            this->vec.at(p)->insert(q, (this->vec.at(n)->get(m)->inhalt));
            cout << "Element kopiert!" << endl;
            vecout();
            break;
        case ELEMENT_LOESCHEN:
            cout << "Listennummer des Elements (0 bis n): ";
            cin >> n;
            cout << endl;
            cout << "Listenposition des Elements das geloescht wird (1 bis n): ";
            cin >> m;
            cout << endl;
            this->vec.at(n)->erase(m);
            cout << "Element geloescht!" << endl;
            vecout();
            break;
        case LISTE_KOPIEREN:
            cout << "Listennummer der Liste (0 bis n): ";
            cin >> n;
            this->vec.push_back(new LinList(*this->vec.at(n)));
            this->listcount++;
            cout << "Liste wurde kopiert mit Nummer " << this->listcount << endl;
            vecout();
            break;
        case LISTE_LOESCHEN:
            cout << "Listennummer die geloescht wird (0 bis n): ";
            cin >> n;
            cout << endl;
            this->vec.at(n)->clear();
            this->vec.at(n) = nullptr;
            this->listcount--;              //buggy
            cout << "Liste geloescht!" << endl;
            vecout();
        case LISTEN_ADDIEREN:
            cout << "Listennummer auf die addiert wird (0 bis n): ";
            cin >> n;
            cout << "Listennummer die addiert wird (0 bis n): ";
            cin >> m;
            this->vec.push_back(&(*(this->vec.at(n)) + *(this->vec.at(m))));
            this->listcount++;
            vecout();
            break;
        case ENDE:
            vecout();
            break;
        default:
            break;
    }
}

/**
 * reads vector
 */
void ListDialog::vecout(){
    for (int i = 0; i < this->listcount ; ++i) {
        cout << "Liste " << i << endl;
        cout << *(this->vec.at(i)) << endl;
        cout << endl;
    }
}

