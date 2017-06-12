/**
* @file: ListDialog.cpp
* @author:DJ MacHack
* @date: 12.06.2017.
* Matrnr.: 3747719
* mail@hendrik-haas.de
*/

#include <iostream>
#include "ListDialog.h"

ListDialog::ListDialog() {
    this->vec.push_back(new LinList());
    this->listcount++;
    cout << "Neue Liste im Vector an Stelle " << this->listcount-1 << endl;
}

ListDialog::ListDialog(LinList *list) {
    this->vec.push_back(list);
    this->listcount++;
    cout << "Neue Liste im Vector an Stelle " << this->listcount-1 << endl;
}

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

    } while (funktion != ENDE);

}

FunktionsTyp ListDialog::einlesenFunktion() {
    cout << LISTE_ANLEGEN << ": Liste anlegen; "
         << ELEMENT_EINFUEGEN << ": Element in die Liste einfuegen; "
         << ELEMENT_LOESCHEN << ": Element aus der Liste loeschen; "
         << LISTE_KOPIEREN << ": Liste kopieren; "
         <<  ELEMENT_KOPIEREN << ": Element kopieren; "
         << LISTE_LOESCHEN << ": Liste löschen; "
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

void ListDialog::ausfuehrenFunktion(FunktionsTyp funktion) {
    std::string inhalt = "";
    int n, m, p, q;
    switch (funktion) {
        case LISTE_ANLEGEN:
            this->vec.push_back(new LinList());
            this->listcount++;
            cout << "Neue Liste im Vector an Stelle " << this->listcount-1 << endl;
            break;
        case ELEMENT_EINFUEGEN:
            cout << "Listennummer: ";
            cin >> n;
            cout << endl;
            cout << "Listenposition: ";
            cin >> m;
            cout << endl;
            cout << "Inhalt: ";
            cin >> inhalt;
            cout << endl;
            this->vec.at(n)->insert(m, inhalt);
            cout << "Element eingefuegt!" << endl;
            break;
        case ELEMENT_KOPIEREN:
            cout << "Listennummer aus der kopiert wird: ";
            cin >> n;
            cout << endl;
            cout << "Listenposition des Elements das kopiert wird: ";
            cin >> m;
            cout << endl;
            cout << "Listennummer in die kopiert wird: ";
            cin >> p;
            cout << endl;
            cout << "Listenposition des Elements das kopiert wird: ";
            cin >> q;
            cout << endl;
            this->vec.at(p)->insert(q, (this->vec.at(n)->get(m)->getInhalt()));
            cout << "Element kopiert!" << endl;
            break;
        case ELEMENT_LOESCHEN:
            cout << "Listennummer des Elements: ";
            cin >> n;
            cout << endl;
            cout << "Listenposition des Elements das geloescht wird: ";
            cin >> m;
            cout << endl;
            this->vec.at(n)->erase(m);
            cout << "Element geloescht!" << endl;
            break;
        case LISTE_KOPIEREN:
            cout << "Listennummer der Liste: ";
            cin >> n;
            this->vec.push_back(new LinList(*this->vec.at(n)));
            this->listcount++;
            cout << "Liste wurde kopiert mit Nummer " << this->listcount << endl;
            break;
        case LISTE_LOESCHEN:
            cout << "Listennummer die geloescht wird: ";
            cin >> n;
            cout << endl;
            this->vec.at(n)->clear();
            this->vec.at(n) = nullptr;
            this->listcount--;
            //todo this->vec.erase()
            cout << "Liste gelöscht!" << endl;
        case ENDE:

            break;
        default:
            break;
    }

}

