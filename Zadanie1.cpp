/*
Meno a priezvisko: Peter Likavec

POKYNY:
(1)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(2)  Cela implementacia musi byt v tomto jednom subore.
(3)  Odovzdajte len tento zdrojovy subor (s vypracovanymi rieseniami).
(4)  Program musi byt kompilovatelny.
(5)  Globalne a staticke premenne su zakazane.
(6)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
     (nemente nazvy, navratove hodnoty, ani typ a pocet parametrov v zadanych funkciach).
     Nemente implementacie zadanych datovych typov, ani implementacie hotovych pomocnych funkcii
     (ak nie je v zadani ulohy uvedene inak).
(7)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo datove typy.
(8)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo datovych typov).
     Testovaci kod ale nebude hodnoteny.
(9)  Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>
#include <climits>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Pozicia v rovine
struct Position {
    int x; // x-ova suradnica
    int y; // y-ova suradnica
};

// Datum
struct Date {
    int year;  // rok
    int month; // mesiac
    int day;   // den
};

// Uspesnost vykonania funkcie
enum class Result {
    SUCCESS, // funkcia vykonana uspesne
    FAILURE  // chyba pri vykonavani funkcie
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia na standardny vystup vytlaci udaje v strukture.
    V implementacii musi byt pouzity 'std::cout'.

    Format tlace musi byt podla nasledujucich prikladov. Bez odriadkovania. Bez uvodzoviek. Dodrzte pouzitie medzier.
    Priklady:
        "x: 10, y: 20"
        "x: -12345, y: 2"

    PARAMETER:
        [in] position - pozicia, ktora bude vytlacena
*/
void print(const Position *position) {
    // TODO
    std::cout << "x: " << position->x<<", " <<"y: "<< position->y;
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Implementujte rovnaku funkcionalitu ako v prvom priklade. Rozdiel je len typ parametra funkcie.
*/
void print(const Position &position) {
    // TODO
    std::cout << "x: " << position.x<<", " <<"y: "<< position.y;
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zo standardneho vstupu nacita postupne dve cisla. Ulozi ich ako x-ovu a y-ovu zlozku pozicie 'position'.
    V implementacii musi byt pouzity 'std::cin' a formatovany vstup.

    PARAMETER:
        - [out] position - pozicia, ktorej hodnoty sa nastavia podla udajov zo standardneho vstupu.

    VSTUPNE PODMIENKY:
        Text zadany na standardny vstup obsahuje dve cele cisla, ktore mozno reprezetovat typom 'int'.
        Nemusite osetrovat moznost chybnych udajov na standardnom vstupe.
 */
void readFromStandardInput(Position *position) {
    std::cout <<"Zadaj cislo x y: ";
    std::cin >> position->x >> position->y;
    std::cout << "x: " << position->x<<", " <<"y: "<< position->y<< std::endl;
    // TODO
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati najvacsiu hodnotu prvku pola 'data' a nastavi 'result' podla uspesnosti hladania.

    Ak pole obsahuje prvky, tak vrati ich maximum a nastavi 'result' na 'SUCCESS'.
    Ak pole neobsahuje ziadne prvky (jeho dlzka je nulova),
    tak vrati minimalnu hodnotu, ktoru moze reprezentovat datovy typ 'int' a nastavi result na 'FAILURE'.

    PARAMETRE:
        [in] data    - adresa zaciatku pola
        [in] length  - pocet prvkov pola (dlzka pola)
        [out] result - indikuje uspesnost najdena maxima

    NAVRATOVA HODNOTA:
        Ak pole obsahuje prvky, tak vrati hodnotu najvacsieho prvku pola 'data'.
        Ak pole neobsahuje prvky, tak vrati minimalnu hodnotu reprezentovatelnu datovym typom 'int'.

    PRIKLADY:
        vstup: (1, 2, 5, 0, 1) => navratova hodnota: 5,  result: 'Result::SUCCESS'
        vstup: (-5, -2, -10)   => navratova hodnota: -2, result: 'Result::SUCCESS'
        vstup: () => navratova hodnota: minimalna hodnota reprezentovatelna datovym typom 'int', result: 'Result::FAILURE'
*/
int maximum(const int *data, std::size_t length, Result *result) {
    // TODO
    int max;
    if (length <= 0){
        *result = Result::FAILURE;
        return INT_MIN; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
    }
    else{
        max = data[0];
        for(std::size_t i = 0; i < length;i++){
            if (data[i]>max){
                max = data[i];
            }
        }
    *result = Result::SUCCESS;
    return max;
    }
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati pocet znakov, ktore su potrebne na zapis cisla 'value' (v desiatkovej ciselnej sustave).

    PARAMETER:
        - [in] value - analyzovana hodnota

    NAVRATOVA HODNOTA:
        Pocet znakov, potrebnych pre textovu reprezentaciu hodnoty 'value'

    PRIKLADY:
        - vstup: 18002 => vystup: 5
        - vstup: 2     => vystup: 1
        - vstup: 0     => vystup: 1
        - vstup: -500  => vystup: 4
*/
int numDigits(int value) {
    // TODO
    int count = 0;
    string str = to_string(value);
    count = str.length();
    return count; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytlaci na standardny vystup datum, podla zadaneho formatu.

    Vytlaceny text bude obsahovat kopiu textu vo 'format', ale
    znak 'D' nahradi dnom,
    znak 'M' nahradi mesiacom,
    znak 'Y' nahradi rokom v datume.

    PARAMETRE:
        - [in] date - datum
        - [in] format - format vylacenia datumu

    PRIKLADY:
        Nech datum je 10. aprila 2020
        - format: "D. M. Y" => "10. 4. 2020"
        - format: "D. M."   => "10. 4."
        - format: "Pisomka bude D. M. Y, v miestnosti BC 300" => "Pisomka bude 10. 4. 2020, v miestnosti BC 300"
        - format: "M/D/Y"   => "4/10/2020"
        - format: "Y-M-D"   => "2020-4-10"

    POZNAMKA:
        Vsimnite si pretazenie funkcie. Tento zdrojovy subor obsahuje 3 funkcie s nazvom 'print'.
*/
void print(const Date *date, const char *format) {
    // TODO;
    int size = 0;
    while(format[size] != '\0'){
        if (format[size] == 'D'){
            cout << date->day;
            size++;   
        }
        else if (format[size] == 'M'){
            cout << date->month;
            size++;   
        }
        else if (format[size] == 'Y'){
            cout << date->year;
            size++;   
        }
        else{
            cout << format[size];
            size++;   
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy datum podla parametrov a vrati jeho adresu.
    Pre dynamicku alokaciu pamate pouzite operator 'new'.

    PARAMETRE:
        [in] day   - den v datume
        [in] month - mesiac v datume
        [in] year  - rok v datume

    NAVRATOVA HODNOTA:
        Adresa na dynamicky alokovany datum, ktoreho obsah je dany parametrami
*/
Date* create(int day, int month, int year) {
    // TODO
    Date * new_date = new Date;
    new_date->day = day;
    new_date->month = month;
    new_date->year = year;
    return new_date; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia dealokuje datum. Smernik na datum nastavi na 'nullptr'.
    Na dealokaciu pamate pouzite operator 'delete'.

    PARAMETER:
        [in, out] date - adresa smernika na datum

    VYSTUPNE PODMIENKY:
        Datum na adrese (*date) je dealokovany.
        (*date) ma hodnotu 'nullptr'.
*/
void destroy(Date **date) {
    // TODO
    delete *date;
    *date = nullptr;
}

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zisti, ci je rok v datume priestupny.

    PARAMETER:
        [in] date - datum

    NAVRATOVA HODNOTA:
        'true'  - ak rok je priestupny
        'false' - ak rok nie je priestupny

    VSTUPNA PODMIENKA:
        Rok v datume je kladne cislo

    URCENIE PRIESTUPNEHO ROKU:
        Rok delitelny cislom 4 je priestupny okrem pripadu, ked je delitelny cislom 100, ale nie je delitelny cislom 400.
        Priklady:
            - priestupne roky: 2000, 2004, 2008
            - nepriestupne roky: 2001, 2002, 2003, 2005, 2006, 2007, 2009, 2010
            - priestupne roky: 1600, 2000, 2400
            - nepriestupne roky: 1500, 1700, 1800, 1900, 2100, 2200, 2300, 2500
*/
bool isInLeapYear(const Date *date) {
    // TODO
    if(date->year%4 == 0){
        if(date->year%100 == 0 && date->year%400 != 0){
            return false;
        }
        else{
            return true;
        }
    }
    else{
            return false;
        }
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia zisti, ci je datum platny.

    Treba overit, ci datum moze existovat. Napriklad
    v januari moze byt den od 1 do 31,
    vo februari od 1 do 28 alebo 29, podla toho, ci je rok priestupny.
    Rok ma mesiac 1 az 12.

    PARAMETER:
        [in] date - datum

    NAVRATOVA HODNOTA:
        'true'  - ak datum je platny
        'false' - ak datum nie je platny

    VSTUPNA PODMIENKA:
        Rok v datume je kladne cislo
*/
bool isValid(const Date *date) {
    // TODO
    int day = date->day;
    int month = date->month;
    int year = date->year;
    if(year < 0 || month <= 0 || day <= 0)
        return false;
    switch (month){
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:{
            if(day <= 31)
                return true;
            else
                return false;
        }
        case 4:case 6:case 9:case 11:{
            if(day <= 30)
                return true;
            else
                return false;
        }
        case 2:{
            bool leap_year = isInLeapYear(date);
            if(leap_year == 1){
                if(day <=29)
                    return true;
                else
                    return false;
            }
            else{
                if(day <=28)
                    return true;
                else
                    return false;
            }
        }
        default:
            return false;
    }
}
//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne testovacie funkcie a struktury

int main() {
    // // //Uloha1
    // Position cords = {-5,-7};
    //     print(&cords);
    // // //Uloha2
    //     cords = {12,-56};
    //     print(cords);
    // // //Uloha3
    //     readFromStandardInput(&cords);
    // // // //Uloha4
    //     int data[] = {-5,-5,-2,-1};
    //     Result result;
    //     size_t lenght = sizeof(data)/sizeof(int);
    //     cout<<lenght<<endl;
    //     cout << maximum(data,lenght,&result)<<std::endl;
        
    // // // //Uloha5
    //     std::cout << (numDigits(5665560)) << endl;
    // //Uloha6
        Date date = {2020,4,10};
        char format[] = "D. M. Y";
        print(&date,format);
        char format2[] = "D. M.";
        print(&date,format2);
        char format3[] = "Pisomka bude D. M. Y, v miestnosti BC 300";
        print(&date,format3);
        char format4[] = "M/D/Y";
        print(&date,format4);
        char format5[] = "Y-M-D";
        print(&date,format5);
    //Uloha7
    //     Date *new_date = create(1,1,2002);
    //     cout << new_date << endl;
    // Uloha8

    // Uloha9
        
    //     date = {1500,1,1};
    //     cout << (isInLeapYear(&date))<< endl; //0
    //     date = {2000,1,1};
    //     cout << (isInLeapYear(&date))<< endl; //1
    //     date = {2004,1,1};
    //     cout << (isInLeapYear(&date))<< endl; //1
    //     date = {2002,1,1};
    //     cout << (isInLeapYear(&date))<< endl; //0
    //     date = {2005,1,1};
    //     cout << (isInLeapYear(&date))<< endl; //0
    //     date = {1600,1,1};
    //     cout << (isInLeapYear(&date))<< endl; //1
    //     date = {1563,1,1};
    //     cout << (isInLeapYear(&date))<< endl; //0
    // Uloha10
    //     date = {2003,2,28};
    //     cout << (isValid(&date))<< endl; //0
    //     date = {2003,2,29};
    //     cout << (isValid(&date))<< endl; //
    //     date = {2003,2,31};
    //     cout << (isValid(&date))<< endl; //
    //     date = {-2003,2,29};
    //     cout << (isValid(&date))<< endl; //
    //     date = {2004,4,17};
    //     cout << (isValid(&date))<< endl; //
        
    return 0;
}
