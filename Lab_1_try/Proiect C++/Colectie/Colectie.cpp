#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>


Colectie::Colectie() {
    this->capacitate = 2;
    this->n = 0;
    this->elemente = new TElem [this->capacitate];
}


void Colectie::adauga(TElem elem) {
    /***
     * O(n)
     */
    if (this->n == this->capacitate ){
        TElem *elementeNoua = new TElem[ 2 * this->capacitate];
        for ( int  i = 0 ; i < this->n ; i ++ )
            elementeNoua[i] = this->elemente[i];
        this->capacitate = 2 * this->capacitate;
        delete[] this->elemente;
        this->elemente = elementeNoua;
    }
    this->elemente[this->n] = elem;
    this->n = this->n + 1;
}


bool Colectie::sterge(TElem elem) {
    /***
     *Teta(n)
     */
    int pozitie = -1;
    for ( int i = 0 ;  i < this->n ; i ++ )
        if ( elem == this->elemente[i] )
            pozitie = i;
    if ( pozitie == -1)
        return false;
    for ( int i = pozitie ; i < (this->n - 1) ; i ++ )
        this->elemente[i] = this->elemente[i+1];
    this->n = this->n - 1;
    return true;
}


bool Colectie::cauta(TElem elem) const {
    /***
     * O(n)
     */
    for ( int i = 0 ; i < this->n ; i ++)
        if ( this->elemente[i] == elem )
            return true;
    return false;
}

int Colectie::nrAparitii(TElem elem) const {
    /***
     * Teta(n)
     */
    int contor = 0;
    for ( int i = 0 ; i < this->n ; i ++ )
        if ( this->elemente[i] == elem )
            contor ++;
    return contor;
}


int Colectie::dim() const {
    /***
     * Teta(1)
     */
    return this->n;
}


bool Colectie::vida() const {
    /***
     * Teta(1)
     */
    if ( this->n == 0)
        return true;
    return false;
}

IteratorColectie Colectie::iterator() const {
    /***
     * Teta(1)
     */
    return IteratorColectie(*this);
}

Colectie::~Colectie() {
    /***
     * Teta(1)
     */
    delete[] this->elemente;
}

int Colectie::Sterge_Nr_Aparitii(int numar_aparitii, TElem elem){
    /// Teta(cont)
    /// unde cont e minimul dintre numarul de aparitii ale elementului in lista si numarul de aparitii date
    int ap = this->nrAparitii(elem);
    int cont = ( ap > numar_aparitii ? numar_aparitii : ap );
    for ( int i = 1 ; i <= cont ; i ++ )
        sterge(elem);
    return cont;
}