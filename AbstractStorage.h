#pragma once
#include "PopulationCensus.h"
#include <queue>
#include <map>
#include <string>
#include "SingleListLink.h"
#include <vector>

using namespace std;

void PrintFreqStat(string field, int freq, int count){
    cout << field << " " << freq << " (" << freq * 200/count << "%)" << endl;
}

class CensusStorage{
public:

    virtual void Add(Census* census) = 0;

    virtual void Remove(int id) = 0;

    virtual Census* SearchByID(int id) = 0;

    virtual Census* SearchByAge(int age) = 0;

    virtual Census* SearchByDate(string date) = 0;

    virtual Census* SearchByPlaceOfBirth(PPlaceOfBirth place) = 0;

    virtual Census* SearchByLanguages(LLanguages language) = 0;

    virtual void Stats() = 0;

};


class QueueCensusStorage : public CensusStorage{
private:
    queue<Census*> storage;
public:
     ~QueueCensusStorage(){
        queue<Census*> empty;
        swap( storage, empty );
    }

     void Add(Census* census){
        storage.push(census);
    }

     void Remove(int id) {
        queue<Census *> p;
        queue<Census *> elem;
        elem.push(storage.front());
        if (storage.front()->ID == id) {
            storage.pop();
        } else {
            p.push(storage.front());
            storage.pop();
            storage.push(p.front());
            while (elem.front() != storage.front()){
                if(storage.front()->ID){
                    storage.pop();
                    break;
                }
            }
        }
    }

     Census* SearchByID(int id){
        queue<Census *> p;
        queue<Census *> elem;
        elem.push(storage.front());
        if (storage.front()->ID == id) {
            return storage.front();
        } else {
            p.push(storage.front());
            storage.pop();
            storage.push(p.front());
            p.pop();
            if(storage.front()->ID == id){
                return storage.front();
            }
            while (elem.front() != storage.front()){
                p.push(storage.front());
                storage.pop();
                storage.push(p.front());
                p.pop();
                if(storage.front()->ID == id){
                    return storage.front();
                }
            }
            cout << "Not Found";
            exit(1);
        }
    }

     Census* SearchByAge(int age){
         queue<Census *> p;
         queue<Census *> elem;
         elem.push(storage.front());
         if (storage.front()->Age == age) {
             return storage.front();
         } else {
             p.push(storage.front());
             storage.pop();
             storage.push(p.front());
             p.pop();
             if(storage.front()->Age == age){
                 return storage.front();
             }
             while (elem.front() != storage.front()){
                 p.push(storage.front());
                 storage.pop();
                 storage.push(p.front());
                 p.pop();
                 if(storage.front()->Age == age){
                     return storage.front();
                 }
             }
             cout << "Not Found";
             exit(1);
         }
    }
    Census* SearchByDate(string date) {
        queue<Census *> p;
        queue<Census *> elem;
        elem.push(storage.front());
        if (storage.front()->Date == date) {
            return storage.front();
        } else {
            p.push(storage.front());
            storage.pop();
            storage.push(p.front());
            p.pop();
            if(storage.front()->Date == date){
                return storage.front();
            }
            while (elem.front() != storage.front()){
                p.push(storage.front());
                storage.pop();
                storage.push(p.front());
                p.pop();
                if(storage.front()->Date == date){
                    return storage.front();
                }
            }
            cout << "Not Found";
            exit(1);
        }
    }

    Census* SearchByPlaceOfBirth(PPlaceOfBirth place) {
        queue<Census *> p;
        queue<Census *> elem;
        elem.push(storage.front());
        if (storage.front()->PlaceOfBirth == place) {
            return storage.front();
        } else {
            p.push(storage.front());
            storage.pop();
            storage.push(p.front());
            p.pop();
            if(storage.front()->PlaceOfBirth == place){
                return storage.front();
            }
            while (elem.front() != storage.front()){
                p.push(storage.front());
                storage.pop();
                storage.push(p.front());
                p.pop();
                if(storage.front()->PlaceOfBirth == place){
                    return storage.front();
                }
            }
            cout << "Not Found";
            exit(1);
        }
    }

    Census* SearchByLanguages(LLanguages len) {
        queue<Census *> p;
        queue<Census *> elem;
        elem.push(storage.front());
        if (storage.front()->Languages == len) {
            return storage.front();
        } else {
            p.push(storage.front());
            storage.pop();
            storage.push(p.front());
            p.pop();
            if(storage.front()->Languages == len){
                return storage.front();
            }
            while (elem.front() != storage.front()){
                p.push(storage.front());
                storage.pop();
                storage.push(p.front());
                p.pop();
                if(storage.front()->Languages == len){
                    return storage.front();
                }
            }
            cout << "Not Found";
            exit(1);
        }
    }

      void Stats() {
        cout << "Statistics" << endl;
        int AgeSum = 0, count = 0;
         map<GGender, int> GenderFreq = {};
         map<PPlaceOfBirth, int> PlaceOfBirthFreq = {};
         map<LLanguages, int> LanguagesFreq = {};
        count++;
        AgeSum += storage.front()->Age;
        GenderFreq[storage.front()->Gender]++;
         PlaceOfBirthFreq[storage.front()->PlaceOfBirth]++;
         LanguagesFreq[storage.front()->Languages]++;
        queue<Census *> p;
        queue<Census *> elem;

        elem.push(storage.front());
        p.push(storage.front());
        storage.pop();
        storage.push(p.front());
        p.pop();
        while(elem.front() != storage.front()){
            count++;
            AgeSum += storage.front()->Age;
            GenderFreq[storage.front()->Gender]++;
            PlaceOfBirthFreq[storage.front()->PlaceOfBirth]++;
            LanguagesFreq[storage.front()->Languages]++;
            p.push(storage.front());
            storage.pop();
            storage.push(p.front());
            p.pop();
        }
        cout << "Average age: " << AgeSum / count << endl;
        cout << endl;
        cout << "Gender frequencies:" << endl;
        PrintFreqStat(PrintGGender(Male), GenderFreq[Male], count);
        PrintFreqStat(PrintGGender(Female), GenderFreq[Female], count);
        PrintFreqStat(PrintGGender(NonBinary), GenderFreq[NonBinary], count);
        cout << endl;
        cout << "Place Of Birth frequencies:" << endl;
        PrintFreqStat(PrintPPlaceOfBirth(Moscow), PlaceOfBirthFreq[Moscow], count);
        PrintFreqStat(PrintPPlaceOfBirth(Ufa), PlaceOfBirthFreq[Ufa], count);
        PrintFreqStat(PrintPPlaceOfBirth(Kazan), PlaceOfBirthFreq[Kazan], count);
         cout << endl;
         cout << "Other languages:" << endl;
         PrintFreqStat(PrintLanguages(English), LanguagesFreq[English], count);
         PrintFreqStat(PrintLanguages(French), LanguagesFreq[French], count);
         PrintFreqStat(PrintLanguages(Nothing), LanguagesFreq[Nothing], count);
    }
};

class ListSensusStorage : public CensusStorage {
private:
    SingleLinkedList storage;

public:
    virtual ~ListSensusStorage(){}

    void Add(Census *i) {
        storage.PushBack(i);
    }

    void Remove(int id) {
        storage.RemoveByID(id);
    }

    Census *SearchByID(int id) {
        auto found = find_if(storage.begin(), storage.end(), [&id](Census *i) {
            return i->ID == id;
        });

        if (found == storage.end()) {
            return nullptr;
        }

        return *found;
    }

    Census *SearchByAge(int age) {
            auto found = find_if(storage.begin(), storage.end(), [&age](Census *i) {
            return i->Age == age;
        });

        if (found == storage.end()) {
            return nullptr;
        }

        return *found;
    }

    Census *SearchByDate(string date) {
        auto found = find_if(storage.begin(), storage.end(), [&date](Census *i) {
            return i->Date == date;
        });

        if (found == storage.end()) {
            return nullptr;
        }

        return *found;
    }

    Census *SearchByPlaceOfBirth(PPlaceOfBirth place) {
        auto found = find_if(storage.begin(), storage.end(), [&place](Census *i) {
            return i->PlaceOfBirth == place;
        });

        if (found == storage.end()) {
            return nullptr;
        }

        return *found;
    }

    Census *SearchByLanguages(LLanguages languages) {
        auto found = find_if(storage.begin(), storage.end(), [&languages](Census *i) {
            return i->Languages == languages;
        });

        if (found == storage.end()) {
            return nullptr;
        }

        return *found;
    }

    void Stats() {
        cout << "Statistics" << endl;
        int AgeSum = 0, count = 0;
        map<GGender, int> GenderFreq = {};
        map<PPlaceOfBirth, int> PlaceOfBirthFreq = {};
        map<LLanguages, int> LanguagesFreq = {};
        for (auto const &census: storage) {
            count++;
            AgeSum += census->Age;
            GenderFreq[census->Gender]++;
            PlaceOfBirthFreq[census->PlaceOfBirth]++;
            LanguagesFreq[census->Languages]++;
        }
        cout << "Average age: " << AgeSum / count << endl;
        cout << endl;
        cout << "Gender frequencies:" << endl;
        PrintFreqStat(PrintGGender(Male), GenderFreq[Male], count);
        PrintFreqStat(PrintGGender(Female), GenderFreq[Female], count);
        PrintFreqStat(PrintGGender(NonBinary), GenderFreq[NonBinary], count);
        cout << endl;
        cout << "Place Of Birth frequencies:" << endl;
        PrintFreqStat(PrintPPlaceOfBirth(Moscow), PlaceOfBirthFreq[Moscow], count);
        PrintFreqStat(PrintPPlaceOfBirth(Ufa), PlaceOfBirthFreq[Ufa], count);
        PrintFreqStat(PrintPPlaceOfBirth(Kazan), PlaceOfBirthFreq[Kazan], count);
        cout << endl;
        cout << "Other languages:" << endl;
        PrintFreqStat(PrintLanguages(English), LanguagesFreq[English], count);
        PrintFreqStat(PrintLanguages(French), LanguagesFreq[French], count);
        PrintFreqStat(PrintLanguages(Nothing), LanguagesFreq[Nothing], count);
    }
};




