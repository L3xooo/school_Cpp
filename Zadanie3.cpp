/*
Meno a priezvisko: Peter Likavec

POKYNY:
(1)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.ri
(2)  Cela implementacia musi byt v tomto jednom subore.
(3)  Odovzdajte len tento zdrojovy subor (s vypracovanymi eseniami).
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
#include <cstring>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Uzol zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // smernik na dalsi uzol zoznamu
};

// Zretazeny zoznam
struct List {
    Node* first; // smernik na prvy uzol zoznamu
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada pole 'data' od najvacsieho prvku po najmensi prvok.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'length' moze mat lubovolnu hodnotu
        'data' ukazuje na platne pole

    PRIKLADY:
        (1, 3, 2) -> (3, 2, 1)
        (1, 2, 2, 1) -> (2, 2, 1, 1)
        (1) -> (1)
        () -> ()
*/
void insertionSort(int *data, const size_t length) {
    for(size_t j = 1;j<length;j++){
        int currentElement = data[j];
        int k = j-1;

        while(k>=0 && currentElement>data[k]){
            data[k+1] = data[k];
            --k;
            cout << "K = " << k<<endl;
        }
        data[k+1] = currentElement;
    }
    // TODO
}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada textove retazce v poli 'data' od najvacsieho prvku po najmensi (lexikograficky).
    Preusporiadajte smerniky v poli.
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada.
                Pole obsahuje smerniky na textove retazce.
                Kazdy textovy retazec je ukonceny '\0'.
                Posledny smernik ma hodnotu 'nullptr'. Podla toho urcite pocet prvkov pola (pocet textovych retazcov).

    VSTUPNE PODMIENKY:
        'data' obsahuje minimalne jeden smernik.
        Posledny smernik ma hodnotu 'nullptr'.

    PRIKLADY:
        ("Juraj", "Peter", "Andrej", nullptr) -> ("Peter", "Juraj", "Andrej", nullptr)
        ("Juraj", "Anabela", "Peter", "Andrej", nullptr) -> ("Peter", "Juraj", "Andrej", "Anabela", nullptr)
        ("Andrej", "Juraj", "Andrej", nullptr) -> ("Juraj", "Andrej", "Andrej", nullptr)
        ("Andrej", "Frantisek",nullptr) -> ("Frantisek","Andrej", nullptr)
        ("Andrej", nullptr) -> ("Andrej", nullptr)
        (nullptr) -> (nullptr)

    POZNAMKY:
        Pri testovani mozete jednoducho pole vytvorit nasledovnym sposobom:
        const char *mena[] = {"Juraj", "Peter", "Andrej", nullptr};

        Na porovnanie obsahu textovych retazcov vyuzite prislusnu funkciu zo standardnej kniznice.
*/
void insertionSort(const char *data[]) {
    const char *currentWord;
    int position = 1;
    int j = position-1;
    if(data[0] && data[1]){
        currentWord = data[1];
        while(currentWord!= nullptr){
            while( j>= 0 && strcmp(currentWord,data[j]) >= 0 ){
                data[j+1] = data[j];
                --j;
            }
            data[j+1] = currentWord;
            position++;
            j = position-1;
            currentWord = data[position];
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada zretazeny zoznam 'list' od najvacsieho prvku po najmensi.
    Preusporiadajte uzly v zozname (nekopirujte hodnoty v uzloch).
    Pouzite algoritmus insertion sort.

    PARAMETRE:
        [in, out] list - zretazeny zoznam, ktory funkcia usporiada

    VSTUPNE PODMIENKY:
        'list' obsahuje lubovolny pocet uzlov (moze byt prazdny)
        'list' nie je 'nullptr'

    PRIKLADY:
        vstup: 2->1->3,        vystup: 3->2->1
        vstup: 1->2->2->1,     vystup: 2->2->1->1
        vstup: prazdny zoznam, vystup: prazdny zoznam
*/
void insertionSort(List * list) {
    Node *currentNode;
    Node *tmp;
    Node *lastSorted;
    Node *previousNode = nullptr;
    if(list->first && list->first->next){
        tmp = list->first;
        currentNode = list->first->next;
        previousNode = nullptr;
        lastSorted = list->first;
        while(currentNode){
            // cout << "Counter = " << counter <<endl;
            // cout << "List->First = "<<list->first->data<< " Tmp = "<< tmp->data <<
            // " Currentnode = "<< currentNode->data << " LastSorted = "<< lastSorted->data << endl;
            tmp = list->first;
            while(true){
                if(currentNode->data < tmp->data){  //posuvanie tmp
                    if(tmp == lastSorted){          //ak je tmp zaroven posledny usporiaddany0
                        lastSorted = currentNode;   //set posledny isporiadany na current a breakni
                        break;
                    }
                    else{
                    previousNode = tmp;             //nastavi predchdzajuci
                    tmp = tmp->next;
                    continue;
                    }
                }
                else{                           //tmp je mensie ako current
                    if(tmp == list->first){                     //tmp je prvy
                        lastSorted->next = currentNode->next;   //nastavim poslednu sorted na poziciu curr
                        currentNode->next = list->first;        //setnem cur pozicuu na list.first
                        list->first = currentNode;              //setnem novy listfirst
                    }
                    else{                                       //tmp nie je prvy
                        lastSorted->next = currentNode->next;
                        currentNode->next = tmp;
                        previousNode->next = currentNode;
                    }
                    break;
                }
            }
            currentNode = lastSorted->next;
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vykona algoritmus merge (cast algoritmu merge sort), ktory ma linearnu vypoctovu zlozitost.
    Kombinuje dve susedne, usporiadane casti v poli 'input', do jednej usporiadanej casti v poli 'output'.
    Usporiadanie je od najvacsieho prvku po najmensi prvok!

    PARAMETRE:
        [out] output - vystupne pole, ktoreho cast output[low]...output[high-1] bude po vykonani funkcie usporiadana
        [in]  input  - vstupne pole, ktoreho casti input[low]...input[middle-1] a input[middle]...input[high-1]
                         musia byt pri volani funkcie usporiadane od najvacsieho prvku po najmensi
        [in]  low    - index 1. prvku lavej usporiadanej casti pola 'input'
        [in]  middle - index 1. prvku pravej usporiadanej casti pola 'input'
        [in]  high   - index za poslednym prvkom pravej usporiadanej casti pola 'input'

    VYSTUPNE PODMIENKY:
        Obsah 'input' je nezmeneny.
        output[low] ... output[high-1] obsahuje usporiadane prvky z input[low] ... input[high-1], zvysne prvky v 'output' funkcia nemeni.
        Prvky s indexami mensimi ako 'low' sa nemenia (ani v jednom poli).
        Prvky s indexami vacsimi alebo rovnymi ako 'high' sa nemenia (ani v jednom poli).

    PRIKLAD:
        low: 4
        middle: 8
        hight: 12
        input:                         (10, 10, 10, 10,  7,  5,  2,  0,  8,  4,  2,  1, 10, 10, 10, 10)
        output pred vykonanim funkcie: (20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20)
        output po vykonani funkcie:    (20, 20, 20, 20,  8,  7,  5,  4,  2,  2,  1,  0, 20, 20, 20, 20)
*/
void mergeNeighbours(int *output, const int *input, const size_t low, const size_t middle, const size_t high) {
    size_t L = low;
    size_t M = middle;
    for(size_t a = 0; a < (size_t) high-low ; a++){
        if(L < middle && input[L] > input[M]) {
            output[a+low] = input[L];
            L++;
        }
        else if(M<high && input[M] > input[L]){
            output[a+low] = input[M];
            M++;
        }
        else if(L >= middle){
            output[a+low] = input[M];
            M++;
        }
        else{
            output[a+low] = input[L];
            L++;
        }
    }
}

//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.8 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia usporiada prvky v poli 'data' od najvacsieho prvku po najmensi.
    Pouzite algoritmus merge sort.
    Vytvorte jedno pomocne pole. Pre alokaciu a dealokaciu pomocneho pola pouzite new[] a delete[].

    PARAMETRE:
        [in, out] data - pole, ktore funkcia usporiada
        [in] length    - pocet prvkov pola

    VSTUPNE PODMIENKY:
        'data' ukazuje na platne pole

    PRIKLADY:
        (1, 3, 2) -> (3, 2, 1)
        (1, 2, 2, 1) -> (2, 2, 1, 1)
        (1) -> (1)
        () -> ()

    POZNAMKA:
        Ak pouzijete pristup top-down, tak
        - v tejto funkcii zabezpecte vytvorenie a kopirovanie dat do pomocneho pola,
        - vytvorte a zavolajte rekurzivnu funkciu, v ktorej implementujete hlavnu cast algoritmu merge sort.
*/
// void mergeSort(int *arrayA, int *arrayB, const size_t low, const size_t high) { // Priklad deklaracie rekurzivnej funkcie, v pripade pristupu top-down
// }

void mergeArrays(int array[],int left, int middle, int right){
    size_t array1_lenght = middle - left + 1;
    size_t array2_lenght = right - middle;
    size_t a;
    int *array1 = new int[array1_lenght];
    int *array2 = new int[array2_lenght];

    for(a = 0; a < array1_lenght ;a++){
        array1[a] = array[left+a];
    }
    for(a = 0; a < array2_lenght ;a++){
        array2[a] = array[middle+a+1];
    }

    size_t L = 0, M = 0;

    while(L<array1_lenght && M < array2_lenght){
        if(array1[L] > array2[M]){
            array[left] = array1[L];
            L++;
        }
        else{
            array[left] = array2[M];
            M++;
        }
        left++;
    }
    while(true){
        if(L < array1_lenght){
            array[left] = array1[L];
            L++;
            left++;
        }
        else if (M < array2_lenght){
            array[left] = array2[M];
            M++;
            left++;
        }
        else{
            break;
        }  
    }
    delete[] array1;
    delete[] array2;
}

void mergeSort(int *data, const size_t length) {
    size_t size;
    int counter = 0;
    for(size = 1 ; size <length ;size = size*2){
        //cout << "Cycle_number = " << counter << endl;
        for(size_t left = 0; left < length ; left = left+(size*2)){
            int middle = min(left+size-1,length-1);
            int right = min(left+2*size-1,length-1);
            //cout << "Left = " << left << " Middle = " << middle+1 << " Right = " << right << endl;
            mergeArrays(data,left,middle,right);
        }
        counter++;
    }
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------



void sortedPrint(int *data,const size_t lenght){
    for(size_t i = 0; i < lenght ; i++){
        cout << "Index : " << i << " " << " number : " << data[i] << endl;
    }
}

void insertionPrint(const char *data[]){
    const char *ptr;
    ptr = data[0];
    size_t counter = 0;
    while(ptr != nullptr){
        cout << ptr << endl;
        counter++;
        ptr = data[counter];
    }
}
void listPrint(List *list){
    Node *current = list->first;
    while(true){
        cout << "Node.data = " << current->data << endl;
        if(current->next == nullptr){
            cout << "Node.next = nullptr" << endl;
            break;}
        // else
        //     cout << "Node.next = " << current->next << endl;

        current = current->next;
    }
}
// tu mozete doplnit pomocne funkcie a struktury

int main() {
    //Uloha1
        // int array[] = {1,2,3,4};
        // insertionSort(array,4);
        // sortedPrint(array,4);
    //Uloha2
        // const char *mena[] = {"andrej", nullptr};
        // insertionSort(mena);
        // insertionPrint(mena);
    //Uloha3
        // Node devat = {6,nullptr};
        // Node osem = {5,&devat};
        // Node sedem = {1,&osem};
        // Node sest = {12,&sedem};

        // Node frth = {10,&sest};
        // Node thrd = {2,&frth};
        // Node scnd = {3,&thrd};
        // Node fst = {4,&scnd};
        // List list = {&fst};
        // insertionSort(&list);
        // listPrint(&list);

    //Uloha4
        // int array[] = {10, 10, 10, 10,  19, 18, 17, 16, 8,  4,  2,  1, 10, 10, 10, 10};
        // int output[] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20};

        // mergeNeighbours(output,array,4,8,12);
        // sortedPrint(output,16);
    //Uloha5
        int array[] = {1,1,11,11};
        mergeSort(array,sizeof(array)/sizeof(array[0]));
        sortedPrint(array,sizeof(array)/sizeof(array[0]));
    return 0;
}
