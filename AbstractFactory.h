#pragma once
#include "PopulationCensus.h"
#include <string>

using namespace std;

class AbstractFactory
{
public:
    virtual Census* CreateCensus(int id) = 0;
};

string randDate(){
    char dateBuff[100];
    snprintf(dateBuff, sizeof(dateBuff), "%02d.06.2022", rand() % 30);
    return dateBuff;
}

class OldPeopleFactory : public AbstractFactory{
public:
    virtual Census* CreateCensus(int id){
        Census* census = new Census;

        census->ID = id;
        census->Age = 40 + rand() % 100;
        census->Gender = static_cast<GGender>(rand() % 3);
        census->Name = static_cast<NName>(rand() % 3);
        census->Education = static_cast<EEducation>(rand() % 3);
        census->Date = randDate();
        census->PlaceOfBirth = static_cast<PPlaceOfBirth>(rand() % 3);
        census->YearOfContinuousResidence = rand() % 100;
        census->LivedInOtherCountries = static_cast<YesNoAnswer>(rand() % 2);
        census->Languages = static_cast<LLanguages>(rand() % 3);
        census->UsedEverydayDay = static_cast<YesNoAnswer>(rand() % 2);
        census->ProficiencyInRussian = static_cast<YesNoAnswer>(rand() % 2);
        census->EnumerationAreaNumber = rand() % 1000;
        census->HouseholdNumberWithinTheEnumerationArea = rand() % 4;
        census->BlankNumber = rand() % 10000;
        census->Marriage = static_cast<MMarriage>(rand() % 4);
        census->Plans = "Спать и отдыхать, ведь я сдал курсовую";
        census->Mark = 5;
        census->Conclusion = "Всё получилось как и хотел";
        census->SourceOfIncome = static_cast<SSourceOfIncome>(rand() % 3);

        return census;
    }
};

class YoungPeopleFactory : public AbstractFactory{
public:
    virtual Census* CreateCensus(int id){
        Census* census = new Census;

        census->ID = id;
        census->Age = rand() % 39;
        census->Gender = static_cast<GGender>(rand() % 3);
        census->Name = static_cast<NName>(rand() % 3);
        census->Education = static_cast<EEducation>(rand() % 3);
        census->Date = randDate();
        census->PlaceOfBirth = static_cast<PPlaceOfBirth>(rand() % 3);
        census->YearOfContinuousResidence = rand() % 100;
        census->LivedInOtherCountries = static_cast<YesNoAnswer>(rand() % 2);
        census->Languages = static_cast<LLanguages>(rand() % 3);
        census->UsedEverydayDay = static_cast<YesNoAnswer>(rand() % 2);
        census->ProficiencyInRussian = static_cast<YesNoAnswer>(rand() % 2);
        census->EnumerationAreaNumber = rand() % 1000;
        census->HouseholdNumberWithinTheEnumerationArea = rand() % 4;
        census->BlankNumber = rand() % 10000;
        census->Marriage = static_cast<MMarriage>(rand() % 4);
        census->Plans = "Сдать курсовую :с ";
        census->Mark = 3;
        census->Conclusion = "В следующий раз точно сделаю лучше";
        census->SourceOfIncome = static_cast<SSourceOfIncome>(rand() % 3);

        return census;
    }
};

