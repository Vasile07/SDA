//
// Created by Irimieş Vasile on 3/31/2023.
//
#include <cassert>
#include "test_sterse.h"
#include "Proiect C++/Colectie/Colectie.h"

bool Prim(int nr){
    if ( nr < 2 )
        return false;

    for ( int d = 2; d*d <= nr ; d ++ )
        if( nr % d == 0 )
            return false;

    return true;
}

void test_stergere_multipla(){
    Colectie c = Colectie();
    for ( int i = 1 ; i <= 37; i ++ )
        if(Prim(i))
            c.adauga(2);
        else
            c.adauga(i);

    assert ( c.nrAparitii(2) == 12) ;
    assert ( c.Sterge_Nr_Aparitii(7, 2) == 7);
    assert ( c.nrAparitii(2) == 5);
    assert ( c.Sterge_Nr_Aparitii(7, 2) == 5);
    assert ( c.nrAparitii(2) == 0);
}
