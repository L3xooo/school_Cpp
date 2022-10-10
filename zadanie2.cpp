/*
Meno a priezvisko:

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

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Reprezentacia uzla zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node *next; // adresa nasledujuceho uzla zoznamu
};

// Reprezentacia zretazeneho zoznamu
struct List {
    Node *first; // adresa prveho uzla zoznamu
};

// Pomocna struktura pre ulohu 2
struct ListData {
    int *data; // pole hodnot uzlov
    size_t len; // dlzka pola 'data'
};

//-------------------------------------------------------------------------------------------------
// 1. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy uzol s hodnotou 'val' na koniec zretazeneho zoznamu 'list'.

    VSTUPNE PODMIENKY:
        1) Plati, ze 'list' vzdy existuje (t.j. 'list' je rozny od 'nullptr') a moze
           mat lubovolny pocet uzlov (0 a viac).

    PARAMETRE:
        [in, out] list - adresa zretazeneho zoznamu, do ktoreho ideme pridavat uzol
        [in] val       - hodnota uzla, ktory sa ma pridat na koniec zoznamu 'list'

    NAVRATOVA HODNOTA:
        Ziadna.

    PRIKLADY:
        (), 5 ---> (5)
        (1), 1 ---> (1,1)
        (8,2,6,6), 14 ---> (8,2,6,6,14)
        (6,100,33), -85 ---> (6,100,33,-85)
        (1,2,3,4,5), 3 ---> (1,2,3,4,5,3)
*/

void appendNode(List *list, const int val) {
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    Node *currentNode = list->first;

    while(true){
        if(list->first == nullptr){
            list->first = newNode;
            break;
        }
        if(currentNode->next == nullptr){
            currentNode->next = newNode;
            break;
        }
        else{
            currentNode = currentNode->next;
        }
    }

}

//-------------------------------------------------------------------------------------------------
// 2. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy zretazeny zoznam, ktory bude skonstruovany pomocou udajov vo vstupnej
    strukture 'listData'. Struktura 'listData' obsahuje polozku 'data', ktora reprezentuje pole
    hodnot pre jednotlive uzly zoznamu. Struktura 'listData' taktiez obsahuje polozku 'len', ktora
    hovori aku ma dlzku pole 'data'. Vytvoreny zoznam musi obsahovat uzly, ktore zodpovedaju
    svojimi hodnotami a poradim prvkom ulozenym v poli 'data' (dlzka zoznamu bude 'len').
    Funkcia nakoniec vrati adresu takto vytvoreneho zoznamu.

    VSTUPNE PODMIENKY:
        1) Plati, ze 'listData' vzdy existuje (t.j. 'listData' je rozny od 'nullptr').
        2) Pre polozku 'len' plati, ze 'len' >= 0 a nikdy nebude mat vacsiu hodnotu ako je
           realny pocet prvkov v poli 'data'.
    VYSTUPNA PODMIENKA:
        1) Ak je polozka 'len' rovna 0, vtedy sa vytvori a vrati prazdny zretazeny zoznam
           (t.j. platny zoznam, ktory ma 0 uzlov).

    PARAMETRE:
        [in] listData - struktura, pomocou ktorej sa vytvori zoznam

    NAVRATOVA HODNOTA:
        Adresa zretazeneho zoznamu, ktory bol vytvoreny pomocou struktury 'listData'.
        Vid pokyny vyssie.

    PRIKLADY:
        polozka 'data' = (1,2,3)
        polozka 'len' = 0
        vystupny zoznam bude mat 0 uzlov, t.j. ()

        polozka 'data' = (1,2,3)
        polozka 'len' = 2
        vystupny zoznam bude (1,2)

        polozka 'data' = (1,2,3)
        polozka 'len' = 3
        vystupny zoznam bude (1,2,3)

        polozka 'data' = (-9,412,64,72,100,100,6)
        polozka 'len' = 4
        vystupny zoznam bude (-9,412,64,72)
*/

List *createList(const ListData *listData) {
    List *firstNode = new List;

    if(listData->len == 0){
        firstNode->first = nullptr;
        return firstNode;
    }

    Node *nodeArray = new Node[listData->len];

    for (size_t i = 0; i < listData->len; i++)
    {
        //cout << i << endl;
        nodeArray[i].data = listData->data[i];
        if (i == listData->len-1){
            nodeArray[i].next = nullptr;
        }
        else{
            nodeArray[i].next = &nodeArray[i+1];
            //cout << listData->data[i]<<endl;
        }
    }
    firstNode->first = &nodeArray[0];
    //cout << "Len : " << listData->len << endl;
    return firstNode; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 3. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia prida novy uzol s hodnotou 'val' do vzostupne zotriedeneho zoznamu 'sortedList'.
    Pridanie musi prebehnut takym sposobom, aby bol zoznam 'sortedList' po pridani noveho uzla
    stale vzostupne zotriedeny.

    POZNAMKA: Na poradi duplikatov v zozname 'sortedList' nezalezi.

    VSTUPNE PODMIENKY:
        1) Plati, ze 'sortedList' vzdy existuje (t.j. 'sortedList' je rozny od 'nullptr').
        2) Vstupny zoznam 'sortedList' moze mat lubovolny pocet uzlov (0 a viac).
        3) Vstupny zoznam 'sortedList' je vzostupne zotriedeny.

    PARAMETRE:
        [in, out] sortedList   - adresa vstupneho zretazeneho zoznamu, ktory je zotriedeny
                                 vzostupne (z angl. ascending)
        [in] val               - hodnota uzla, ktory sa ma pridat do zoznamu 'sortedList'

    NAVRATOVA HODNOTA:
        Ziadna.

    PRIKLADY:
        (), 0 ---> (0}
        (), 156 ---> (156)
        (8), 4 ---> (4,8)
        (7), 10 ---> (7,10)
        (55), 55 ---> (55,55) ... poznamka: na poradi duplikatov nezalezi
        (1,8,236,888), 70 ---> (1,8,70,236,888)
        (5,5,14,82,82,100), 5 ---> (5,5,5,14,82,82,100)
*/

void insertNode(List *sortedList, const int val) {
    Node *currentNode = sortedList->first;
    Node *previousNode = nullptr;
    int count = 0;
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    
    while(true){
        if(sortedList->first == nullptr){
            sortedList->first = newNode;
            break;
        }
        else if(currentNode->data <= val){ //ak je value vacsia 1,2,3,8,10 -------- 7
        //cout << "Currentnode = " << currentNode->data << " " << "Next.data = " << currentNode->next->data<< endl;
           //cout << "Count = " << count<<endl;
            if(currentNode->next == nullptr){
                currentNode->next = newNode;
                break;
            }
            else{
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
        }
        else{                                       //ak je value mensia
            // if(currentNode->next == nullptr){

            //     if(count == 0){
            //         sortedList->first = newNode;
            //         newNode->next = currentNode;
            //         break;
            //     }
            //     else{
            //         previousNode->next = newNode;
            //         newNode->next = currentNode;
            //     }
            //     break;
            // }
          //  else{
                if(count == 0){
                    sortedList->first = newNode;
                    newNode->next = currentNode;
                    break;
                }
                else{
                    previousNode->next = newNode;
                    newNode->next = currentNode;
                    break;
                }

         //   }
        }
    count++;
    }
}

//-------------------------------------------------------------------------------------------------
// 4. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori novy zoznam spojenim zoznamov 'list1' a 'list2'. Funkcia vrati adresu
    novo vytvoreneho zoznamu. V spojenom zozname idu najprv uzly zoznamu 'list1' (v nezmenenom poradi)
    a potom nasleduju uzly zoznamu 'list2' (v nezmenenom poradi). Pri vytvarani noveho zoznamu mozete
    pouzit hlboku alebo plytku kopiu existujucich uzlov (obe riesenia budu akceptovane).

    POZNAMKA:
        Prazdny zoznam je taky zoznam, ktory je platny, ale obsahuje 0 uzlov
        (t.j. polozka 'first' je nastavena na 'nullptr').

    VSTUPNE PODMIENKY:
        1) Zoznamy 'list1' a 'list2' mozu byt lubovolne dlhe (0 a viac uzlov).

    PARAMETRE:
        [in, out] list1 - adresa prveho zoznamu
        [in, out] list2 - adresa druheho zoznamu

    NAVRATOVA HODNOTA:
        Adresa zoznamu, ktory vznikol spojenim zoznamov 'list1' a 'list2'.

    PRIKLADY:
        () + () ---> ()
        (5,9) + () ---> (5,9)
        () + (2,2,2) ---> (2,2,2)
        (1) + (2) ---> (1,2)
        (7) + (3,9,16) ---> (7,3,9,16)
        (50,-47,23,1) + (0,0,9,-8) ---> (50,-47,23,1,0,0,9,-8)
*/

List *joinLists(List *list1, List *list2) {
    List *newList = new List;
    Node *currentNode = new Node;
    if(list1->first == nullptr){
        if(list2->first == nullptr){
            newList->first = nullptr;
            return newList;
        }
        else{
            return list2;
        }
    }
    else{
        if(list2->first == nullptr){
            return list1;
        }
        else{
            currentNode = list1->first;
            while (true){
                if(currentNode->next == nullptr){
                    currentNode->next = list2->first;
                    return list1;
            }
                else{
                    currentNode = currentNode->next;
                }
            }
        }
    }
}
//-------------------------------------------------------------------------------------------------
// 5. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia odstrani posledny uzol zo zoznamu 'list'. Ak je zoznam 'list' prazdny, funkcia nic
    nevykona. Pamat uzla, ktory funkcia vymaze musi byt korektne dealokovana.

    VSTUPNE PODMIENKY:
        1) Plati, ze 'list' vzdy existuje (t.j. 'list' je rozny od 'nullptr').
        2) Zoznam 'list' moze byt lubovolne dlhy (0 a viac uzlov).

    PARAMETRE:
        [in, out] list - adresa vstupneho zoznamu

    NAVRATOVA HODNOTA:
        Ziadna.

    PRIKLADY:
        () ---> ()
        (1) ---> ()
        (1,2) ---> (1)
        (1,2,3) ---> (1,2)
*/

void removeLastNode(List *list) {
    Node *currentNode;
    Node *previousNode = nullptr;
    int i = 0;
    currentNode = list->first;

    while (true){
        //cout << currentNode->data<< " " << "adreasa = " << currentNode->next <<endl ;
        if (list->first == nullptr){
            break;
        }
        if(currentNode->next == nullptr && i == 0){
            list->first = nullptr;
            break;
        }
        if(currentNode->next == nullptr){
            previousNode->next = nullptr;
            break;
        }
        else{
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        i++;
    }
}

//-------------------------------------------------------------------------------------------------
// 6. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia overi, ci je vstupny zoznam 'list' palindrom. Prazdny zoznam budeme povazovat za
    palindrom.

    Poznamka: Palindrom predstavuje taku postupnost hodnot, ktora sa cita rovnako v oboch smeroch.
    URL: https://sk.wikipedia.org/wiki/Palindr%C3%B3m
    Priklad palindromu: 1212121 alebo 4953594

    VSTUPNE PODMIENKY:
        1) Plati, ze 'list' vzdy existuje (t.j. 'list' je rozny od 'nullptr').
        2) Zoznam 'list' moze byt lubovolne dlhy (0 a viac uzlov).

    PARAMETRE:
        [in] list - adresa vstupneho zoznamu

    NAVRATOVA HODNOTA:
        Pravdivostna hodnota 'true'/'false' podla toho, ci vstupny zoznam je/nie je palindrom.

    PRIKLADY:
        () ---> true
        (1) ---> true
        (2,2,2,2) ---> true
        (1,2,3,4,5) ---> false
        (1,2,2,1) ---> true
        (8,4,8,4,8) ---> true
        (9,842,613,2,613,842,9) ---> true
        (7,9,1,2) ---> false
        (0,0,0,7,0,0) ---> false
*/

bool isPalindrome(const List *list) {
    int succes = 0;
    size_t count = 0;
    int tmp = 0;
    Node *currentNode = new Node;
    int *array = new int[20];
    if(list->first == nullptr){
        return true;
    }

    currentNode = list->first;
    while(true){
        if(currentNode->next == nullptr){
            if(count == 0){
                return true;
            }
            else{
                array[count] = currentNode->data; //add last element
                tmp = count;
                //cout << "Tmp = " << tmp << "Count = " << count << endl;
                count = count/2 + 1;
                //cout << "Count new = " << count << endl;
                for(size_t j = 0; j < count; j++,tmp--){
                    //cout << "Array_j = " << array[j] << " Array_tmp = " << array[tmp] << " " << tmp << "count = " << j << endl ;
                    if(array[j] == array[tmp]){
                        succes++;
                        continue;
                        }
                    else{
                        return false;
                    }
                }
                if(count == succes)
                    return true;
                else
                    return false;
            }
        }
        else{
            array[count] = currentNode->data;
            currentNode = currentNode->next;
        }
    count++;
    }
}

//-------------------------------------------------------------------------------------------------
// 7. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vrati sucet hodnot prvych 'n' uzlov v zozname 'list'.

    VSTUPNE PODMIENKY:
        1) Plati, ze 'list' vzdy existuje (t.j. 'list' je rozny od 'nullptr').
        2) Zoznam 'list' moze byt lubovolne dlhy (0 a viac uzlov).
        3) Parameter 'n' nebude zaporny a nebude mat nikdy vyssiu hodnotu ako je realny pocet
           uzlov v zozname.

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] n - pocet uzlov od zaciatku zoznamu 'list', ktorych sucet sa vrati

    NAVRATOVA HODNOTA:
        Sucet hodnot prvych 'n' uzlov zoznamu 'list'. Ak 'n'=0, vtedy funkcia vrati hodnotu 0.

    PRIKLADY:
        (), 0 ---> 0
        (1,2,3), 0 ---> 0
        (6), 1 ---> 6
        (5,6,7), 2 ---> 11
        (4,4,4,4,4,4), 6 ---> 24
        (-8,41,-314,21), 3 ---> -281
*/

int sumNodes(const List *list, const size_t n) {
    int sum = 0;
    Node *currentNode;
    currentNode = list->first;
    for(size_t j = 0; j < n ; j++){
        sum += currentNode->data;
        currentNode = currentNode->next;
    }
    return sum; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// 8. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia overi, ci zoznam 'list1' obsahuje vsetky hodnoty uzlov zoznamu 'list2'.
    Na poradi nezalezi.

    VSTUPNE PODMIENKY:
        1) Plati, ze 'list1' a 'list2' vzdy existuju (t.j. su rozne od 'nullptr').
        2) Zoznamy 'list1' a 'list2' mozu byt lubovolne dlhe (0 a viac uzlov).
        3) Zoznam 'list2' nebude obsahovat duplicitne uzly.

    PARAMETRE:
        [in] list1 - prvy zoznam
        [in] list2 - druhy zoznam

    NAVRATOVA HODNOTA:
        Pravdivostna hodnota 'true'/'false' podla toho, ci zoznam 'list1' obsahuje/neobsahuje
        vsetky hodnoty uzlov zoznamu 'list2'.

    PRIKLADY:
        (), () ---> true
        (), (1,2,3) ---> false
        (1,2,3), () ---> true
        (5,6,7), (5,6,8) ---> false
        (8,4,3), (3,8,4) ---> true
        (7,6,1,9,8), (1,6,8) ---> true
        (3,3,3,3,3), (2,3) ---> false
        (8,6,1,2,5,0,7,7), (7) ---> true
        (9,5,10), (41,10,5) ---> false
*/

bool contains(const List *list1, const List *list2) {
    // TODO
    int count = 0;
    int success = 0;
    Node *currentNode;
    Node *currentNode1;
    if(list1->first == nullptr){
        if(list2->first == nullptr){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(list2->first == nullptr){
            return true;
        }
        currentNode = list2->first;
        
        while(true){
            currentNode1 = list1->first;
            while(true){
                cout << "list = " <<currentNode1->data<<" "<< "list2 = "<<currentNode->data<<endl; 
                if(currentNode->data == currentNode1->data){
                    success++;
                    cout << "succes = " <<success<<endl;
                    break;
                }
                else if(currentNode1->next == nullptr){
                    return false;
                }
                else{
                    currentNode1 = currentNode1->next;
                }
            }
            count++;
            cout << "Count = " << count <<endl;
            if(currentNode->next == nullptr){
                break;
            }
            else{
                currentNode = currentNode->next;
            }
        }
        if(count == success){
                return true;
        }
        else{
            return false;
        }
    }
}


//-------------------------------------------------------------------------------------------------
// 9. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia vytvori a vrati HLBOKU kopiu zoznamu 'list'. Vo vytvorenej kopii musia byt zachovane
    hodnoty a poradie uzlov z povodneho zoznamu.

    VSTUPNE PODMIENKY:
        1) Plati, ze 'list' vzdy existuje (t.j. je rozny od 'nullptr').
        2) Zoznam 'list' moze byt lubovolne dlhy (0 a viac uzlov).

    PARAMETRE:
        [in] list - adresa zoznamu, ktoreho hlboku kopiu treba vytvorit

    NAVRATOVA HODNOTA:
        Adresa zoznamu, ktory vznikol ako hlboka kopia vstupneho zoznamu 'list'. Kopiou
        prazdneho zoznamu je prazdny zoznam.

    PRIKLADY:
        Vstup = ()
        Vystup = ()

        Vstup = (1,2,3)
        Vystup = (1,2,3)
        Poznamka: adresy uzlov na rovnakych poziciach v oboch zoznamoch sa musia lisit
        (pretoze je to hlboka kopia)
*/


List *deepCopyList(const List *list) {
    int count = 0;
    List *deepCopy = new List;
    Node *currentNode = new Node;
    currentNode = list->first;
    if(list->first == nullptr){
        deepCopy->first = nullptr;
        return deepCopy;
    }
    while(true){
        if(currentNode->next == nullptr){
            count++;
            break;
        }
        else{
            currentNode = currentNode->next;
            count++;
        }
    }
    Node *newNode = new Node[count]; 
    //cout <<"count = "<< count<<endl;
    int count1 = 0;
    currentNode = list->first;
    for(size_t j = 0;j<count;j++){
        cout << "Adresa dalsieho = " << currentNode->next << endl;
        newNode[j].data = currentNode->data;
        if(currentNode->next != nullptr)
            newNode[j].next = &(newNode[j+1]);
        else
            newNode[j].next = nullptr;
        cout << "Data nove = " << newNode[j].data <<" "<< "Data povodneho = " << currentNode->data <<endl;
       
        cout << "Adresa noveho = "<< &(newNode[j])<< " "<<"Adresa povodneho = "<<currentNode<<endl;
        currentNode = currentNode->next;
    }
    deepCopy->first = &(newNode[0]);
    return deepCopy;
}

//-------------------------------------------------------------------------------------------------
// 10. ULOHA (0.4 bodu)
//-------------------------------------------------------------------------------------------------
/*
    Funkcia najde posledny vyskyt uzla s hodnotou 'val' v zozname 'list' a vrati jeho adresu.
    Ak sa v zozname 'list' takyto uzol nenachadza, funkcia vrati 'nullptr'.

    VSTUPNE PODMIENKY:
        1) Plati, ze 'list' vzdy existuje (t.j. je rozny od 'nullptr').
        2) Zoznam 'list' moze byt lubovolne dlhy (0 a viac uzlov).

    PARAMETRE:
        [in] list - vstupny zretazeny zoznam
        [in] val - hladana hodnota uzla

    NAVRATOVA HODNOTA:
        Adresa posledneho vyskytu uzla s hodnotou 'val' v zozname 'list'.

    PRIKLADY (treba otestovat pomocou debuggera):
        (), 2 ---> nullptr
        (5,4,3,2), 1 ---> nullptr
        (-5,4,-9,66), 4 ---> adresa 2. uzla
        (1,1,1,5,6,41), 1 ---> adresa 3. uzla
        (8,6,7,3,2,6), 6 ---> adresa 6. uzla
*/

Node *findLastNodeOccurrence(const List *list, const int val) {
    Node *currentNode;
    Node *returnedNode = nullptr;
    currentNode = list->first;

    if(list->first == nullptr){
        cout << "SA";
        return nullptr;
    }

    while(true){
        if(currentNode->next == nullptr){
            if(currentNode->data == val){
                returnedNode = currentNode;
                return returnedNode;
            }
            else{
                return returnedNode;
            }
        }
        else{
            if(currentNode->data == val){
                returnedNode = currentNode;
                currentNode = currentNode->next;
            }
            else{
                currentNode = currentNode->next;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne testovacie funkcie a struktury

void listPrint(List *list){
    Node *current = list->first;
    while(true){
        cout << "Node.data = " << current->data << endl;
        if(current->next == nullptr){
            cout << "Node.next = nullptr" << endl;
            break;}
        else
            cout << "Node.next = " << current->next << endl;

        current = current->next;
    }
}


int main() {
    //Uloha1 --mlao by funogvat
        // Node fifth = {5,nullptr};
        // Node frth = {4,&fifth};
        // Node thrd = {3,&frth};
        // Node scnd = {2,&thrd};
        // Node fst = {1,&scnd};
        // List list = {nullptr};
        // appendNode(&list,3);
        // listPrint(&list);


    //Uloha2    -- malo by funogvat

        // int pole[] = {1,2,3};
        // ListData Data_list = {pole,0};
        // List *adress = (createList(&Data_list));

        // Node *current = adress->first;
        // while(true){
        //     cout << "Node.data = " << current->data << endl;
        //     //cout << "Node.next = " << current->next << endl;
        //     if(current->next == nullptr){
        //         break;
        //     }
        //     current = current->next;
        // }

    // //Uloha3 -- malo by funogvat
    //     Node sedem = {100,nullptr};
    //     Node sest = {82,&sedem};
    //     Node frth = {888,nullptr};
    //     Node thrd = {236,&frth};
    //     Node scnd = {8,&thrd};
    //     Node fst = {1,&scnd};
    //     List list = {&fst};
    //     insertNode(&list,70);
    //   //  cout << "PRVY = " << list.first->data << endl;
    //     listPrint(&list);

    //Uloha4    --malo by funogvat
        // Node devat = {-8,nullptr};
        // Node osem = {9,&devat};
        // Node sedem = {0,&osem};
        // Node sest = {2,nullptr};

        // Node frth = {1,nullptr};
        // Node thrd = {23,&frth};
        // Node scnd = {9,nullptr};
        // Node fst = {1,nullptr};

        // List list1  = {&fst};
        // List list2  = {&sest};

        // List *mergedList = joinLists(&list1,&list2);
        // listPrint(mergedList);

    //Uloha5 --funguje
        Node thrd = {3,nullptr};
        Node scnd = {2,&thrd};
        Node fst = {1,&scnd};
        List list = {nullptr};
        removeLastNode(&list);

        Node *current = list.first;
        while(true){
            cout << "Node.data = " << current->data << endl;
            cout << "Node.next = " << current->next << endl;
            if(current->next == nullptr){
                break;
            }
            current = current->next;
        }
    //Uloha6 -- malo by fungovat
        // Node sixth = {4,nullptr};

        // Node fifth = {7,nullptr};
        // Node frth = {0,&fifth};
        // Node thrd = {8,&frth};
        // Node scnd = {0,&thrd};
        // Node fst = {7,&scnd};

        // List list = {&fst};
        // cout << isPalindrome(&list);

    //ULoha7    --funguje
        // Node sixth = {4,nullptr};
        // Node fifth = {4,&sixth};
        // Node frth = {21,&fifth};
        // Node thrd = {-314,&frth};
        // Node scnd = {41,&thrd};
        // Node fst = {-8,&scnd};
        // List list = {&fst};
        // cout << (sumNodes(&list,3));
    //Uloha8
        // Node sixth = {4,nullptr};
        // Node fifth = {3,nullptr};
        // Node frth = {3,&fifth};
        // Node thrd = {10,nullptr};
        // Node scnd = {5,&thrd};
        // Node fst = {9,&scnd};
        // List list = {&fst};
        // //
        // Node sixth1 = {4,nullptr};
        // Node fifth1 = {4,&sixth1};
        // Node frth1 = {21,&fifth1};
        // Node thrd1 = {5,nullptr};
        // Node scnd1 = {10,&thrd1};
        // Node fst1 = {41,&scnd1};
        // List list1 = {&fst1};
        // cout <<(contains(&list,&list1));
    //Uloha9
        // Node thrd = {3,nullptr};
        // Node scnd = {2,&thrd};
        // Node fst = {1,&scnd};
        // List list = {&fst};
        // cout << "Adresa povodneho listu = "<<&list<<endl;
  
        // cout <<(deepCopyList(&list));
       // cout << "Adress1 = "<< &fst << "Adress2 = "<< (deepCopyList(&list))->first;

    //Uloha10   --funguje
        // Node frth = {1,nullptr};
        // Node thrd = {-1,&frth};
        // Node scnd = {1,&thrd};
        // Node fst = {1,&scnd};

        // List list = {&fst};

        // cout << &frth << endl;

        // cout << "Last adress = " << (findLastNodeOccurrence(&list,1));
    return 0;
}
