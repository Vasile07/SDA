#include "Matrice.h"

#include <exception>
#include <iostream>

using namespace std;


Matrice::Matrice(int m, int n) {
	/* de adaugat */
    if ( m <= 0 || n <=0 )
        throw exception();

    primLiber = 0;
    for ( int i = 0 ; i < M ; i ++ ){
        Linii[i] = -1;
        Coloane[i] = -1;
        Valoare[i] = NULL_TELEMENT;
        urm[i] = -1;
    }
    nrLin = m;
    nrCol = n;
}



int Matrice::nrLinii() const{
	return nrLin;
}


int Matrice::nrColoane() const{
	return nrCol;
}


TElem Matrice::element(int i, int j) const{
    if ( i < 0 || j < 0 || i > nrLin || j > nrCol)
        throw exception();
	int poz = disperie(i, j);
    while( poz != -1 ){
        if ( Linii[poz] == i && Coloane[poz] == j )
            return Valoare[poz];
        poz = urm[poz];
    }
	return NULL_TELEMENT;
}


TElem Matrice::modifica(int i, int j, TElem elem) {

    if ( i < 0 || j < 0 || i > nrLin || j > nrCol)
        throw exception();

    int poz = disperie(i, j);

    if ( elem == NULL_TELEMENT ){ // Cazul in care stergem
        int ant = -1;
        int k = 0;
        while ( k < M && urm[k] != poz)
            k++;
        if ( k < M ) ant = k;

        while( poz != -1 && (Linii[poz] != i || Coloane[poz] != j)){
            ant = poz;
            poz = urm[poz];
        }

        if ( poz == -1) return NULL_TELEMENT;

        TElem veche = Valoare[poz];
        bool gata = false;
        do {
            int p = urm[poz];
            int pp = poz;
            while ( p != -1 && disperie(Linii[p], Coloane[p]) != poz){
                pp = p;
                p = urm[p];
            }
            if ( p == -1){
                gata = true;
            }
            else{
                Linii[poz] = Linii[p]; Coloane[poz] = Coloane[p]; Valoare[poz] = Valoare[p];
                poz = p;
                ant = pp;
            }
        }while(!gata);
        if ( ant != -1 )
            urm[ant] = urm[poz];
        Linii[poz] = -1; Coloane[poz] = -1; Valoare[poz] = NULL_TELEMENT;
        urm[poz] = -1;
        if ( poz < primLiber)
            primLiber = poz;
        return veche;
    }
    else{ // Cazul in care modificam sau adaugam
        int ant = -1;
        while ( poz != -1 && ( Linii[poz] != i || Coloane[poz] != j)) {
            ant = poz;
            poz = urm[poz];
        }
        if ( poz != -1){//Modificam
                Linii[poz] = i;
                Coloane[poz] = j;
                TElem veche = Valoare[poz];
                Valoare[poz] = elem;
                return veche;
        }
        else{//Adaugam

            int k = disperie(i,j);
            if ( Valoare[k] == NULL_TELEMENT){
                Valoare[k] = elem;
                Linii[k] = i;
                Coloane[k] = j;
            }
            else{
                urm[ant] = primLiber;
                Valoare[primLiber] = elem;
                Linii[primLiber] = i;
                Coloane[primLiber] = j;
                primLiber = nextLiber();
            }
            return NULL_TELEMENT;
        }
    }
}

int Matrice::disperie(int i, int j) const {
    return (i+j) % M;
}

int Matrice::nextLiber() const {
    for ( int i =primLiber+1; i < M ; i ++ ) {
        if (Valoare[i] == NULL_TELEMENT)
            return i;
    }
}