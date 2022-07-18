#pragma once
#include <string>

using namespace std;

int idnew = 500001;
string NotAvailable = "N/A";

enum NName : int {
    Dima,
    Kolya,
    Other,
};

enum GGender : int {
    Male,
    Female,
    NonBinary
};

enum EEducation : int {
    None,
    School,
    Graduate
};

enum PPlaceOfBirth : int {
    Moscow,
    Ufa,
    Kazan
};

enum YesNoAnswer :int
{
    Yes,
    No
};

enum LLanguages : int {
    English,
    French,
    Nothing
};

enum MMarriage :int
{
    RegisteredMarriage,
    UnregisteredMaritalUnion,
    OfficiallyDivorced,
    NeverMarried
};

enum SSourceOfIncome :int
{
    Parents,
    Work,
    Nope
};

string PrintNName(NName n){
    switch (n) {
        case Dima:
            return "Dima";
        case Kolya:
            return "Kolya";
        case Other:
            return "Other";
    }
    return NotAvailable;
}

string PrintGGender(GGender g){
    switch (g) {
        case Male:
            return "None";
        case Female:
            return "Female";
        case NonBinary:
            return "NonBinary";
    }
    return NotAvailable;
}

string PrintEEducation(EEducation e){
    switch (e) {
        case None:
            return "None";
        case Graduate:
            return "Graduate";
        case School:
            return "School";
    }
    return NotAvailable;
}
string PrintPPlaceOfBirth(PPlaceOfBirth p){
    switch (p) {
        case Moscow:
            return "Moscow";
        case Ufa:
            return "Ufa";
        case Kazan:
            return "Kazan";
    }
    return NotAvailable;
}
string PrintYesNoAnswer(YesNoAnswer y){
    switch (y) {
        case Yes:
            return "Yes";
        case No:
            return "No";
    }
    return NotAvailable;
}
string PrintLanguages(LLanguages l){
    switch (l) {
        case English:
            return "English";
        case French:
            return "French";
        case Nothing:
            return "Nothing";
    }
    return NotAvailable;
}

string PrintMarriage(MMarriage m){
    switch (m) {
        case RegisteredMarriage:
            return "RegisteredMarriage";
        case UnregisteredMaritalUnion:
            return "UnregisteredMaritalUnion";
        case OfficiallyDivorced:
            return "OfficiallyDivorced";
        case NeverMarried:
            return "NeverMarried";
    }
    return NotAvailable;
}

string PrintSourceOfIncome(SSourceOfIncome s){
    switch (s) {
        case Parents:
            return "Parents";
        case Work:
            return "Work";
        case Nope:
            return "Nope";
    }
    return NotAvailable;
}

///////////////////////////////////////////////////

class Census {
public:
    int ID;
    int Age;
    GGender Gender;
    NName Name;
    EEducation Education;
    string Date;
    PPlaceOfBirth PlaceOfBirth;
    int YearOfContinuousResidence;
    YesNoAnswer LivedInOtherCountries;
    LLanguages Languages;
    YesNoAnswer UsedEverydayDay;
    YesNoAnswer ProficiencyInRussian;
    int EnumerationAreaNumber;
    int HouseholdNumberWithinTheEnumerationArea;
    int BlankNumber;
    MMarriage  Marriage;
    string Plans;
    int Mark;
    string Conclusion;
    SSourceOfIncome SourceOfIncome;

    void InputGender() {
        cout << "Пол (0. Муж, 1. Жен, 2. Другое)" << ":" << endl;
        int i;
        cin >> i;
        Gender = static_cast<GGender>(i);
    }

    void InputAge() {
        cout << "Возраст" << ":" << endl;
        cin >> Age;
    }

    void InputName() {
        cout << "Ваше имя (0. Дима, 1. Коля, 2. Другое)" << ":" << endl;
        int i;
        cin >> i;
        Name = static_cast<NName>(i);
    }

    void InputEducation() {
        cout << "Уровень образования (0. Нет, 1. Школа, 2. Университет)" << ":" << endl;
        int i;
        cin >> i;
        Education = static_cast<EEducation>(i);
    }

    void InputDate() {
        cout << "Дата" << ":" << endl;
        cin.ignore();
        getline(cin, Date);
    }

    void InputPlaceOfBirth() {
        cout << "Город рождения (0. Москва, 1. Уфа, 2. Казань)" << ":" << endl;
        int i;
        cin >> i;
        PlaceOfBirth = static_cast<PPlaceOfBirth>(i);
    }

    void InputYearOfContinuousResidence() {
        cout << "Сколько лет вы непрерывно проживаете в этом населенном пункте" << ":" << endl;
        cin >> YearOfContinuousResidence;
    }

    void InputLivedInOtherCountries() {
        cout << "Проживали ли вы более 12 месяцев в других странах (0. Да, 1. Нет)" << ":" << endl;
        int i;
        cin >> i;
        LivedInOtherCountries = static_cast<YesNoAnswer>(i);
    }

    void InputLanguages() {
        cout << "Владеете ли другим языком (0. Английским, 1. Французским, 2. Не владею)" << ":" << endl;
        int i;
        cin >> i;
        Languages = static_cast<LLanguages>(i);
    }

    void InputUsedEveryDay() {
        cout << "Используете ли в повседневной жизни другие языки (0. Да, 1. Нет)" << ":" << endl;
        int i;
        cin >> i;
        UsedEverydayDay = static_cast<YesNoAnswer>(i);
    }

    void InputProficiencyInRussian() {
        cout << "Хорошо ли вы знаете русский язык (0. Да, 1. Нет)" << ":" << endl;
        int i;
        cin >> i;
        ProficiencyInRussian = static_cast<YesNoAnswer>(i);
    }

    void InputEnumerationAreaNumber() {
        cout << "Номер переписного участка" << ":" << endl;
        cin >> EnumerationAreaNumber;
    }

    void InputHouseholdNumberWithinTheEnumerationArea() {
        cout << "Номер помещения в пределах счетного участка" << ":" << endl;
        cin >> HouseholdNumberWithinTheEnumerationArea;
    }

    void InputBlankNumber() {
        cout << "Номер бланка" << ":" << endl;
        cin >> BlankNumber;
    }

    void InputMarriage() {
        cout << "Ваше состояние в браке (0. состою в зарегистрированном бракe, 1. состою в незарегистрированном супружеском союзе, 2. разведен(а) официально, 3. никогда не состоял(а) в браке, супружеском союзе)" << ":" << endl;
        int i;
        cin >> i;
        Marriage = static_cast<MMarriage>(i);
    }

    void InputPLans() {
        cout << "Планы" << ":" << endl;
        cin.ignore();
        getline(cin, Plans);
    }

    void InputMark() {
        cout << "Оценка за курсовую" << ":" << endl;
        cin >> Mark;
    }

    void InputConclusion() {
        cout << "Вывод" << ":" << endl;
        cin.ignore();
        getline(cin, Conclusion);
    }

    void InputSourceOfIncome() {
        cout << "Источник дохода (0. Родители, 1. Работа, 2. Его нет)" << ":" << endl;
        int i;
        cin >> i;
        SourceOfIncome = static_cast<SSourceOfIncome>(i);
    }

};

Census* InputCensus(){
    Census* census = new Census;
    census->ID = idnew;
    census->InputGender();
    census->InputAge();
    census->InputName();
    census->InputEducation();
    census->InputDate();
    census->InputPlaceOfBirth();
    census->InputYearOfContinuousResidence();
    census->InputLivedInOtherCountries();
    census->InputLanguages();
    census->InputUsedEveryDay();
    census->InputProficiencyInRussian();
    census->InputEnumerationAreaNumber();
    census->InputHouseholdNumberWithinTheEnumerationArea();
    census->InputBlankNumber();
    census->InputMarriage();
    census->InputPLans();
    census->InputMark();
    census->InputConclusion();
    census->InputSourceOfIncome();
    cout << "Added, ID" << census->ID;
    idnew++;
    return census;
}

void PrintCensus(Census* census){
    cout << "ID " << census->ID << endl;
    cout << "\tAge: " << census->Age << endl;
    cout << "\tGender: " << PrintGGender(census->Gender) << endl;
    cout << "\tName: " << PrintNName(census->Name) << endl;
    cout << "\tEducation: " << PrintEEducation(census->Education) << endl;
    cout << "\tDate: " << census->Date << endl;
    cout << "\tPlaceOfBirth: " << PrintPPlaceOfBirth(census->PlaceOfBirth) << endl;
    cout << "\tYearOfContinuousResidence: " << census->YearOfContinuousResidence << endl;
    cout << "\tLivedInOtherCountries: " << PrintYesNoAnswer(census->LivedInOtherCountries) << endl;
    cout << "\tLanguages: " << PrintLanguages(census->Languages) << endl;
    cout << "\tUsedEveryDay: " << PrintYesNoAnswer(census->UsedEverydayDay) << endl;
    cout << "\tProficiencyInRussian: " << PrintYesNoAnswer(census->ProficiencyInRussian) << endl;
    cout << "\tEnumerationAreaNumber: " << census->EnumerationAreaNumber << endl;
    cout << "\tHouseholdNumberWithinTheEnumerationArea: " << census->HouseholdNumberWithinTheEnumerationArea << endl;
    cout << "\tBlankNumber: " << census->BlankNumber << endl;
    cout << "\tMarriage: " << PrintMarriage(census->Marriage) << endl;
    cout << "\tPlans: " << census->Plans << endl;
    cout << "\tMark: " << census->Mark << endl;
    cout << "\tConclusion: " << census->Conclusion << endl;
    cout << "\tSourceOfIncome: " << PrintSourceOfIncome(census->SourceOfIncome) << endl;
}