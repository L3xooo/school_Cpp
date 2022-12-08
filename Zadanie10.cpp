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
#include <iomanip>
#include <cassert>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <algorithm>
#include <limits>

using namespace std;

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Upravte definiciu metody 'T::met()' tak, aby informovala, ze metoda nemeni stav objektu.

    Pre kontrolu odkomentujte riadok v testovacej funkcii. Odkomentovany riadok musi byt kompilovatelny.
*/

class T {
public:
    void met() const {}
};

void testUloha1() {
    cout << "----- 1. uloha (metoda nemeni stav objektu) ------------------------------------" << endl;
    const T o;
    o.met(); // odkomentujte
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Upravte definiciiu konstruktora tak, aby bol konverznym konstruktorom.

    Zakomentovane riadky v testovacom kode musia byt kompilovatelne.
*/

class Number {
private:
    int number;
public:
    Number(int value) : number(value){
    }
    int getValue() const {
        return number;
    }
};

void fun(Number n) {
    cout << n.getValue() << endl;
}

void testUloha2() {
    cout << "----- 2. uloha (konverzny konstruktor) -----------------------------------------" << endl;

    Number a = 10; // ak existuje zodpovedajuci konverzny konstruktor, tak je tento riadok kompilovatelny
    cout << a.getValue() << endl;
    fun(20); // ak existuje zodpovedajuci konverzny konstruktor, tak je tento riadok kompilovatelny
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vytvorte triedu 'B', ktora je podtriedou triedy 'A'.
    Upravte definiciu metody 'A::met()' a definujte metodu 'B::met()' tak,
    aby bol testovaci kod po odkomentovani uspesne vykonany (aby bola vzdy volana spravna metoda).
*/

class A {
public:
    virtual char met() const {
        cout << "Class a" << endl;
        return 'a';
    }
};

class B : public A{
public:
    char met() const override{
        cout << "Class b" << endl;
        return 'b';
    }
};

void testUloha3() {
    cout << "----- 3. uloha (volanie spravnej metody) ---------------------------------------" << endl;

    A a;
    B b;

    A *pa  = &a;
    A *pab = &b;
    B* pb  = &b;

    assert(pa->met()  == 'a'); // volanie A::met()
    assert(pab->met() == 'b'); // volanie B::met()
    assert(pb->met()  == 'b'); // volanie B::met()
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Upravte definicie destruktorov tried 'C' a 'D' tak, aby sa v testovacej funkcii zavolal spravny destruktor.
    Testovacia funkcia musi namiesto:
        C::~C()
    po uprave vypisat:
        D::~D()
        C::~C()
*/

class C {
public:
    virtual ~C() {
        cout << "C::~C()" << endl;
    }
};

class D : public C {
public:
    ~D() {
        cout << "D::~D()" << endl;
    }
};

void testUloha4() {
    cout << "----- 4. uloha (volanie spravneho destruktora) ---------------------------------" << endl;
    C *obj = new D;
    delete obj; // aby sa zavolal spravny detruktor
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vytvorte operator +=, ktory bude sluzit pre pripocitanie druheho komplexneho cisla ku prvemu.
    Operator definujte ako clena triedy.

    Pre kontrolu odkomentujte riadky v testovacom kode, kde je priklad pouzitia operatora.
*/

class Complex {
private:
    int real;
    int imaginary;
public:
    Complex(int realPart, int imaginaryPart)
    : real(realPart)
    , imaginary(imaginaryPart) {
    }
    int getRealPart() const {
        return real;
    }
    int getImaginaryPart() const {
        return imaginary;
    }
    Complex operator += (Complex const &Number){
        this->real += Number.real;
        this->imaginary += Number.imaginary;
        return *this;
    }

        // TODO tu pridajte operator +=
};

ostream& operator << (ostream& output,Complex const &obj){
    char sign;
    if(obj.getImaginaryPart() > 0)
        output <<to_string(obj.getRealPart()) << "+" << to_string(obj.getImaginaryPart()) << "i";
    else
        output <<to_string(obj.getRealPart()) << to_string(obj.getImaginaryPart()) << "i";
    return output;
}

void testUloha5() {
    cout << "----- 5. uloha (operator +=) ---------------------------------------------------" << endl;

    Complex a(1,2);
    Complex b(10, 20);
    Complex c(100, 200);

   c += b += a;

   assert(a.getRealPart() == 1);
   assert(a.getImaginaryPart() == 2);
   assert(b.getRealPart() == 11);
   assert(b.getImaginaryPart() == 22);
   assert(c.getRealPart() == 111);
   assert(c.getImaginaryPart() == 222);
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Vytvorte operator <<, ktory zapise hodnotu objektu triedy 'Complex' (z predchadzajuceho prikladu)
    do textoveho prudu dat.
    Poznamka: Operator musi byt definovany ako globalny.

    Pre kontrolu odkomentujte riadky v testovacom kode.
*/

// TODO tu definujte operator <<

void testUloha6() {
    cout << "----- 6. uloha (operator << ) --------------------------------------------------" << endl;

    Complex a( 1, +2);
    Complex b(-3,-4);
   cout << "a = " << a << ", b = " << b << endl;

   ostringstream stream;
   stream << a << " " << b;
   //cout << stream.str();
   assert(stream.str() == "1+2i -3-4i");
}

//=================================================================================================
// STROM - definicia pre dalsie ulohy
//=================================================================================================

// Uzol stromu
struct Node {
    char value; // hodnota uzla
    list<Node*> children; // zoznam nasledovnikov

    explicit Node(char value) : value(value) {}
};

// Strom
struct Tree {
    Node * root; // koren stromu

    explicit Tree(Node *root = nullptr) : root(root) {}
};

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati zoznam vsetkych hodnot uzlov v strome 'tree', ktorych hodnotou je velke pismeno.
    Pouzite algoritmus hladania DO HLBKY.
    Pouzite iterativnu implementaciu.
    Doporucenie: pre identifikaciu velkych pismen pouzite funkciu 'std::isupper'

    VSTUPNA HODNOTA:
        [in] tree - prehladavany strom

    NAVRATOVA HODNOTA:
        zoznam velkych pismen, ktore su hodnotami uzlov v strome 'tree'

    VYSTUPNA PODMIENKA:
        Poradie vo vystupnom zozname musi zodpovedat postupnosti prehladavania algoritmom DO HLBKY.

    PRIKLAD:
        na obrazku
*/

list<char> depthFirstSearchUpperCases(const Tree *tree) {
    list<char> result;
    stack<Node *> Stack;
    Node *actualNode;
    if(tree == nullptr)
        return result;
    Stack.push(tree->root);
    while(!Stack.empty()){
        actualNode = Stack.top();
        Stack.pop();
        if(isupper(actualNode->value)){
            result.push_back(actualNode->value);
            cout << actualNode->value << " ";
        }
        if(!actualNode->children.empty()){ 
                for(auto const& i: actualNode->children){
                    Stack.push(i);
                }
        }
    }
    return result; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati zoznam vsetkych hodnot uzlov v strome 'tree', ktorych hodnotou je velke pismeno.
    Pouzite algoritmus hladania DO SIRKY.
    Pouzite iterativnu implementaciu.
    Doporucenie: pre identifikaciu velkych pismen pouzite funkciu 'std::isupper'

    VSTUPNA HODNOTA:
        [in] tree - prehladavany strom

    NAVRATOVA HODNOTA:
        zoznam velkych pismen, ktore su hodnotami uzlov v strome 'tree'

    VYSTUPNA PODMIENKA:
        Poradie vo vystupnom zozname musi zodpovedat postupnosti prehladavania algoritmom DO SIRKY.

    PRIKLAD:
        na obrazku
*/

list<char> breadthFirstSearchUpperCases(const Tree *tree) {
    list<char> result;
    queue<Node *> Que;
    Node *actualNode;
    if(tree == nullptr)
        return result;
    Que.push(tree->root);
    while(!Que.empty()){
        actualNode = Que.front();
        Que.pop();
        if(isupper(actualNode->value)){
            result.push_back(actualNode->value);
            cout << actualNode->value << " ";
        }
        if(!actualNode->children.empty()){ 
                for(auto const& i: actualNode->children){
                    Que.push(i);
                }
        }
    }
    return result; // tento riadok zmente podla zadania, je tu len kvoli kompilacii    
}

//=================================================================================================
// GRAF - definicia pre dalsie ulohy
//=================================================================================================
// Graf reprezentuje cestnu siet medzi obcami na planete.
// Uzol grafu reprezentuje obec.
// Hrana grafu reprezentuje "priame" cestne spojenie z jednej obce do druhej.
// Graf je orientovany -> Hrana grafu reprezentuje moznost jazdy len jednym smerom.
//  Preto je moznost "priamej" jazdy medzi obcami oboma smermy reprezentovana dvoma hranami grafu.
// Graf je ohodnoteny -> Mapa cestnej siete eviduje dlzky "priamych" cestnych spojeni medzi obcami.
// Obce nemusia byt prepojene cestnou sietou, napriklad ak sa nachadzaju na roznych pevninach.

// Forward deklaracie su potrebne, pretoze:
//  - definicie 'City' a 'RoadTo' su cyklicky zavisle:
//      - v definicii 'City' je pouzite 'RoadTo'
//      - a v definicii 'RoadTo' je pouzite 'City'
//  - definicie 'City' a 'SearchData' su cyklicky zavisle:
//      - v definicii 'City' je pouzite 'SearchData'
//      - a v definicii 'SearchData' je pouzite 'City'
struct RoadTo;
struct City;

// Udaje pouzite v algoritmoch hladania
struct SearchData {
    // Mozete si doplnit dalsie atributy a metody, ktore pouzijete v algoritmoch hladania
    bool discovered;
    unsigned distance;
    const City *previous;
    bool foundShortestPath;

    void clear() { // nastavi na implicitne hodnoty (tuto metodu mozete upravit (ale nie jej deklaracnu cast - nedoplnajte parametre))
        discovered = false;
        distance = numeric_limits<unsigned>::max();
        previous = nullptr;
        foundShortestPath = false;
    }
};

// Obec (uzol grafu)
struct City {
    string name; // nazov obce
    list<RoadTo> roads; // zoznam "priamych" jednosmernych cestnych spojeni do dalsich obci (zoznam vystupnych hran z tohto uzla grafu)

    SearchData searchData; // udaje pouzite v algoritmoch hladania

    // Mozete doplnit dalsi konstruktor alebo metody, ale tento konstruktor nemente
    explicit City(string name) : name(move(name)) {
        searchData.clear();
    };
};

// Jednosmerne "priame" cestne spojenie do dalsej obce (orientovana, ohodnotena hrana grafu)
struct RoadTo {
    City *city; // obec, do ktorej je toto "priame" cestne spojenie
    unsigned length; // dlzka tohto "priameho" spojenia

    // Mozete doplnit dalsi konstruktor alebo metody, ale tento konstruktor nemente
    RoadTo(City *city, unsigned length)
    : city(city)
    , length(length) {
    }
};

// Cestna mapa planety (orientovany, ohodnoteny graf)
struct Planet {
    list<City> cities; // zoznam obci na planete (zoznam vrcholov grafu)

    void clearSearchData() { // inicializuje atributy pouzite v algoritme hladania
        for(City &c : cities) {
            c.searchData.clear();
        }
    }
};

// Vyminka v pripade neexistencie obce so zadanym nazvom
class CityNotExistsException : exception {
    string cityName; // nazov obce
public:
    explicit CityNotExistsException(string name)
    : cityName(move(name)) {
    }
    const char * what() const noexcept override { // vrati nazov neexistujucej obce
        return cityName.c_str();
    }
};

//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati zoznam nazvov vsetkych obci na planete 'planet',
    ktore su z obce s nazvom 'startCity' dosiahnutelne pomocou cestnej siete.
    Pouzite algoritmus hladania DO SIRKY.

    VSTUPNA HODNOTA:
        [in] planet - cestna siet na planete
        [in] startCity - nazov obce

    NAVRATOVA HODNOTA:
        zoznam nazvov vsetkych obci, dosiahnutelnych z obce 'startCity'

    VYNIMKA:
        CityNotExistsException - ak na planete 'planet' neexistuje obec s nazvom 'startCity'.
        Metoda 'CityNotExistsException::what()' vrati nazov neexistujucej obce (hodnota 'startCity').

    VYSTUPNE PODMIENKY:
        Vystupny zoznam obsahuje aj 'startCity'.
        Poradie vo vystupnom zozname musi zodpovedat postupnosti prehladavania algoritmom DO SIRKY.

    PRIKLAD:
        na obrazku

    POZNAMKA:
        Ak v implementacii pouziteje 'City::searchData',
        tak bude pravdepodobne potrebne na zaciatku zavolat 'planet->clearSearchData()',
        aj aby bolo osetrene viacnasobne volanie algoritmu s tym istym objektom 'planet'.
*/

list<string> breadthFirstSearchReachable(Planet * planet, const string & startCity) {
    planet->clearSearchData();
    list<string> Result;
    queue<City*> Que;
    City* actualCity;
    size_t count = 0;
    string test = startCity;
    for(auto &city : planet->cities){
        if(startCity == city.name){
            Que.push(&city);
            city.searchData.discovered = true;
            break;
        }
        count++;
    }
    if(count == planet->cities.size()){
        throw CityNotExistsException(startCity);
    }
    while(!Que.empty()){
        actualCity = Que.front();
        Que.pop();
        Result.push_back(actualCity->name);        
        cout << actualCity->name << ", ";
        if(!actualCity->roads.empty()){
            for(auto const& city:actualCity->roads){
                if(city.city->searchData.discovered == false)
                    Que.push(city.city);
                    city.city->searchData.discovered = true;
            }
        }
    }
    return Result; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia najte dlzky najkratsich ciest z obce 'startCity' do vsetkych dosiahnutelnych obci.
    Pouzite Dijkstrov algoritmus.

    VSTUPNE HODNOTY:
        [in] planet - cestna siet na planete
        [in] startCity - nazov obce

    NAVRATOVA HODNOTA:
        Pre kazdu obec dosiahnutelnu zo 'startCity' (na planete 'planet') obsahuje dlzku najkratsej cesty zo 'startCity'.

    VYNIMKA:
        CityNotExistsException - ak na planete 'planet' neexistuje obec s nazvom 'startCity'.
        Metoda 'CityNotExistsException::what()' vrati nazov neexistujucej obce (hodnota 'startCity').

    VYSTUPNA PODMIENKA:
        Navratova hodnota obsahuje nazvy len tych miest, ktore su dosiahnutelne zo 'startCity'.
        Navratova hodnota obsahuje aj vzdialenost do 'startCity' (nula).

    PRIKLAD:
        na obrazku

    POZNAMKA:
        Ak v implementacii pouziteje 'City::searchData',
        tak bude pravdepodobne potrebne na zaciatku zavolat 'planet->clearSearchData()',
        aj aby bolo osetrene viacnasobne volanie algoritmu s tym istym objektom 'planet'.
*/

map<string, unsigned> dijkstra(Planet * planet, const string & startCity) {
    planet->clearSearchData();
    map<string,unsigned> Result;
    queue<City*> Que;
    City* actualCity;
    size_t count = 0;
    string test = startCity;
    unsigned actualDistance = 0;
    for(auto &city : planet->cities){
        if(startCity == city.name){
            Que.push(&city);
            city.searchData.discovered = true;
            break;
        }
        count++;
    }
    if(count == planet->cities.size()){
        throw CityNotExistsException(startCity);
    }
    while(!Que.empty()){
        actualCity = Que.front();
        actualDistance = Result[actualCity->name];
        cout << "Actual distance = " << actualDistance << " Actual city = " << actualCity->name << endl;
        Que.pop();
        if(!actualCity->roads.empty()){
            for(auto const& city:actualCity->roads){
                if(city.city->searchData.discovered == false)
                    Que.push(city.city);

                    city.city->searchData.discovered = true;
                    map<string,unsigned>::iterator it = Result.find(city.city->name);
                    if(it != Result.end()){
                        cout << "nasiel som" << endl;
                        if(it->second > actualDistance+city.city->searchData.distance){
                            Result[city.city->name] = actualDistance+city.city->searchData.distance;
                            cout << "Prepisujem distance" << endl;
                        }
                        else
                            cout << "Neprepisujem distance" << endl;
                    }
                    else{
                        cout << "Nenasiel som vytvaram novy obj" << endl;
                        Result.insert({city.city->name,actualDistance+city.city->searchData.distance});
                        cout << "Vytvoril som novy obj " << city.city->name << " Distance = " << actualDistance+city.city->searchData.distance << endl;
                    }                    
            }
        }




        // if(actualCity->searchData.foundShortestPath == true)
        //     Result.insert({actualCity->name,actualDistance+actualCity->searchData.distance});
        // if(!actualCity->roads.empty()){
        //     for(auto const& city:actualCity->roads){
        //         if(city.city->searchData.discovered == false)
        //             Que.push(city.city);
        //             city.city->searchData.discovered = true;
        //     }
        // }
    }
    return Result; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

int main() {
    //testUloha1();
    //testUloha2();
    //testUloha3();
    //testUloha4();
    //testUloha5();
    //testUloha6();
    // Node node1('D');
    // node1.children = {};
    // Node node2('E');
    // node2.children = {};
    // Node node3('C');
    // node3.children = {&node1,&node2};
    // Node node4('F');
    // node4.children = {};
    // Node node5('B');
    // node5.children = {&node3,&node4};
    // Node node6('H');
    // node6.children = {};
    // Node node7('g');
    // node7.children = {&node6};
    // Node node8('L');
    // node8.children = {};
    // Node node9('j');
    // node9.children = {};
    // Node node10('K');
    // node10.children = {&node8};
    // Node node11('M');
    // node11.children = {};
    // Node node12('N');
    // node12.children = {};
    // Node node13('I');
    // node13.children = {&node9,&node10,&node11,&node12};
    // Node node14('A');
    // node14.children = {&node5,&node7,&node13};
    // Tree first(&node14);
    //  tu mozete doplnit testovaci kod
    //Uloha7    
        //depthFirstSearchUpperCases(&first);
    //Uloha8
        //breadthFirstSearchUpperCases(&first);    
    // City city1("London");
    // City city2("Wisdon");
    // City city3("Melon");
    // City city4("Tilon");
    // City city5("Lion");
    // City city6("Billon");
    // City city7("Turbilon");
    // City city8("Nylon");
    // City city9("Gulidon");
    // City city10("Gaucon");
    // City city11("Etalon");
    // City city12("Tigron");
    // city1.roads = {{&city2,0},{&city3,0}};
    // city2.roads = {{&city4,0},{&city5,0}};
    // city3.roads = {{&city5,0},{&city6,0}};
    // city4.roads = {{&city7,0}};
    // city5.roads = {{&city8,0}};
    // city6.roads = {};
    // city7.roads = {{&city3,0}};
    // city8.roads = {{&city2,0}};
    // city9.roads = {{&city8,0},{&city10,0}};
    // city10.roads = {};
    // city11.roads = {{&city12,0}};
    // city12.roads = {};
    // Planet planet;
    // planet.cities = {city1,city2,city3,city4,city5,city6,city7,city8,city9,city10,city11,city12};
    // breadthFirstSearchReachable(&planet,"London");
    City city1("London");
    City city2("Haron");
    City city3("Pecelon");
    City city4("Nicudon");
    City city5("Ballon");
    City city6("Etalon");
    City city7("Tigron");
    city1.roads = {{&city2,10},{&city3,40},{&city4,100}};
    city2.roads = {{&city3,20}};
    city3.roads = {{&city5,10},{&city4,50}};
    city4.roads = {};
    city5.roads = {{&city2,15},{&city4,50}};
    city6.roads = {{&city7,10}};
    city7.roads = {};
    Planet planet;
    planet.cities = {city1,city2,city3,city4,city5,city6,city7};
    for(const auto& a : (dijkstra(&planet,"London")))//dijkstra(&planet,"London");
    {
        cout << a.first << "    " << a.second << endl;
    }
    return 0;
}
