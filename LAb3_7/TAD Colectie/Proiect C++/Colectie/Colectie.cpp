#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;

Nod::Nod(TElem e, PNod urm) {
    this->valoare = e;
    this->urm = urm;
}

TElem Nod::element() {
    return this->valoare;
}

PNod Nod::urmator() {
    return this->urm;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Colectie::Colectie() {
	/* de adaugat */
    this->prim = nullptr;
    this->dimensiune = 0;
}


void Colectie::adauga(TElem elem) {
    PNod q = new Nod(elem, this->prim);
    this->prim = q;
    this->dimensiune = this->dimensiune + 1;
}


bool Colectie::sterge(TElem elem) {
    if(this->vida())
        return false;
    if (this->prim->valoare == elem) {
        PNod de_sters = this->prim;
        this->prim = this->prim->urm;
        delete de_sters;
        this->dimensiune = this->dimensiune - 1;
        return true;
    }
    PNod nod = this->prim;
    while(nod->urm != nullptr){
        if(nod->urm->valoare == elem) {
            PNod de_sters = nod->urm;
            nod->urm = nod->urm->urm;
            delete de_sters;
            this->dimensiune = this->dimensiune - 1;
            return true;
        }
        nod = nod->urm;
    }
	return false;
}


bool Colectie::cauta(TElem elem) const {
	PNod nod = this->prim;
    while(nod != nullptr){
        if(nod->valoare == elem)
            return true;
        nod = nod->urm;
    }
	return false;
}

int Colectie::nrAparitii(TElem elem) const {
	int contor = 0;
    PNod nod = this->prim;
    while(nod != nullptr){
        if(nod->valoare == elem)
            contor++;
        nod = nod->urm;
    }
	return contor;
}


int Colectie::dim() const {

	return this->dimensiune;
}


bool Colectie::vida() const {
	if (this->dimensiune == 0)
        return true;
	return false;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	/* de adaugat */;
    while(this->prim != nullptr) {
        PNod de_sters = this->prim;
        this->prim = this->prim->urm;
        delete de_sters;
    }
}


