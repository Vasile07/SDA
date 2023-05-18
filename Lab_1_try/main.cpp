#include <iostream>
//#include "Teste/TestScurt.h"
//#include "Teste/TestExtins.h"
#include "Proiect C++/Colectie/Colectie.h"
#include "Proiect C++/Colectie/IteratorColectie.h"
#include "test_sterse.h"

int main()
{
    //testAll();
    //testAllExtins();
    //std::cout<<"End";
    test_stergere_multipla();
    Colectie c = Colectie();
    for ( int i = 1 ; i <= 37; i ++ )
        if(Prim(i))
            c.adauga(2);
        else
            c.adauga(i);

    IteratorColectie it = c.iterator();
    it.prim();
    while(it.valid()){
        std::cout << it.element() << ' ';
        it.urmator();
    }
    std::cout << '\n';
    std::cout << "NUMAR APARITII INITIALE ALE LUI 2: " << c.nrAparitii(2) << '\n';

    int sterse = c.Sterge_Nr_Aparitii(7, 2);

    it.prim();
    while(it.valid()){
        std::cout << it.element() << ' ';
        it.urmator();
    }
    std::cout << '\n';
    std::cout << "NUMAR APARITII DUPA STERGEREA A 7 ELEMENTE DE 2: " << c.nrAparitii(2) << '\n';
    std::cout << "NUMARUL ELEMENTELOR STERSE: " << sterse;
    return 0;
}