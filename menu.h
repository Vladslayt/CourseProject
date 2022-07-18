#pragma once
#include "PopulationCensus.h"
#include "AbstractStorage.h"
#include "AbstractFactory.h"

using namespace std;

CensusStorage * census;
AbstractFactory* OldFactory;
AbstractFactory *YoungFactory;


void selectEngine() {
    cout << "Engine" << endl;
    cout << "\t1. custom linked list" << endl;
    cout << "\t2. std::queue" << endl;

    int e;
    while (true) {
        cin >> e;
        switch (e) {
            case 1:
                census = new ListSensusStorage;
                return;
            case 2:
                census = new QueueCensusStorage;
                return;
            default:
                cout << "Engine not recognized, try again:" << endl;
        }
    }
}

void searchMenu() {
    cout << "Select field for search" << endl;
    cout << "\t1. by ID" << endl;
    cout << "\t2. by Age" << endl;
    cout << "\t3. by Date" << endl;
    cout << "\t4. by Place Of Birth" << endl;
    cout << "\t5. by Languages" << endl;
    cout << "\t6. Cancel" << endl;

    int m, inp;
    string line;
    Census *i;

    cin >> m;
    switch (m) {
        case 1:
            cout << "Введите критерий по полю " << "ID" << ": ";
            cin >> inp;
            i = census->SearchByID(inp);
            if (i != nullptr) {
                PrintCensus(i);
            } else {
                cout << "Not found" << endl;
            }
            break;
        case 2:
            cout << "Введите критерий по полю " << "Возраст" << ": ";
            cin >> inp;
            i = census->SearchByAge(inp);
            if (i != nullptr) {
                PrintCensus(i);
            } else {
                cout << "Not found" << endl;
            }
            break;
        case 3:
            cout << "Введите критерий по полю " << "Дата" << ": ";
            cin.ignore();
            getline(cin, line);
            i = census->SearchByDate(line);
            if (i != nullptr) {
                PrintCensus(i);
            } else {
                cout << "Not found" << endl;
            }
            break;
        case 4:
            cout << "Введите критерий по полю " << "Город рождения" << ": ";
            cin >> inp;
            i = census->SearchByPlaceOfBirth(static_cast<PPlaceOfBirth>(inp));
            if (i != nullptr) {
                PrintCensus(i);
            } else {
                cout << "Not found" << endl;
            }
            break;
        case 5:
            cout << "Введите критерий по полю " << "Другой язык" << ": ";
            cin >> inp;
            i = census->SearchByLanguages(static_cast<LLanguages>(inp));
            if (i != nullptr) {
                PrintCensus(i);
            } else {
                cout << "Not found" << endl;
            }
            break;
        case 6:
            cout << "Canceled" << endl;
            return;
        default:
            cout << "Field not found, try again" << endl;
            break;
    }
}

const int autoGenerateCount = 250000;

void menu() {
    OldFactory = new OldPeopleFactory;
    YoungFactory = new YoungPeopleFactory;

    for (int i = 1; i <= autoGenerateCount; i++) {
        census->Add(OldFactory->CreateCensus(i));
    }
    for (int i = autoGenerateCount; i <= 2 * autoGenerateCount; i++) {
        census->Add(YoungFactory->CreateCensus(i));
    }

    cout << 2 * autoGenerateCount << " census autogenerated";
    int m, id;
    bool k = true;
    while (k) {
        cout << endl << endl << "Menu" << endl;
        cout << "\t1. Add" << endl;
        cout << "\t2. Remove" << endl;
        cout << "\t3. Search" << endl;
        cout << "\t4. Statistics" << endl;
        cout << "\t5. Exit" << endl;

        cin >> m;
        switch (m) {
            case 1:
                 census->Add(InputCensus());
                break;
            case 2:
                cout << "Укажите ID:" << endl;
                cin >> id;
                census->Remove(id);
                break;
            case 3:
                searchMenu();
                break;
            case 4:
                census->Stats();
                break;
            case 5:
                delete census;
                return;
            default:
                cout << "Menu item not recognized, try again:" << endl;
                k = false;
                break;
        }
    }
    delete OldFactory;
    delete YoungFactory;
}
