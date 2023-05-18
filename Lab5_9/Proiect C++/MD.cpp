#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <algorithm>

using namespace std;


MD::MD() {
    ///Complexitate Teta(NMAX)

	for (int i = 1 ; i < NMAX - 1 ; i ++ ) {
        urm[i] = i + 1;
        prev[i] = i - 1;
    }
    urm[0] = 1;
    prev[0] = -1;
    urm[NMAX - 1] = -1;
    prev[NMAX - 1] = NMAX;

    primLiber = 0;

    prim = ultim = -1;

    lungime = 0;
}


void MD::adauga(TCheie c, TValoare v) {
    /// Complexitate Teta(1)

    TElem elem;
    elem.first = c;
    elem.second = v;
	int i = CreazaNod(elem);
    if ( prim == -1)
    {
        ultim = i;
        urm[ultim] = -1;
        prim = i;
        prev[prim] = -1;
    }
    else{
        urm[i] = prim;
        prev[prim] = i;
        prev[i] = -1;
        prim = i;
    }
    lungime ++;
}


bool MD::sterge(TCheie c, TValoare v) {
    /// Complexitate O(n), n - numarul de elemente in dictionar
	int i = prim;
    TElem elem; elem.first = c; elem.second = v;
    while(i != -1){
        if (e[i] == elem){
            lungime --;
            if ( i == prim ) {
                prim = urm[prim];
                prev[prim] = -1;
            }
            else
                if ( i == ultim ){
                 ultim = prev[ultim];
                 urm[ultim] = -1;
                }
                else {
                    urm[prev[i]] = urm[i];
                    prev[urm[i]] = prev[i];
                }
            dealoca(i);
            return true;
        }
        i = urm[i];
    }
    return false;
}


vector<TValoare> MD::cauta(TCheie c) const {
    /// Complexitate  Teta(n), n - numarul de elemente din dictionar

	vector <TValoare> lista;
    int i = prim;
    while(i != -1){
        if ( e[i].first == c)
            lista.push_back(e[i].second);
        i = urm[i];
    }

	return lista;
}


int MD::dim() const {
    /// Complexitate Teta(1)

	return lungime;
}


bool MD::vid() const {
    /// Complexitate Teta(1)

	if(prim == -1)
	    return true;
    return false;
}

IteratorMD MD::iterator() const {
    /// Complexitate Teta(1)

	return IteratorMD(*this);
}


MD::~MD() {
    /// Complexitate Teta(1)

    delete[] e;
	delete[] urm;
}

int MD::aloca() {
    /// Complexitate Teta(1)

    int i = primLiber;
    primLiber = urm[primLiber];
    return i;
}

void MD::dealoca(int i) {
    /// Complexitate Teta(1)

    urm[i] = primLiber;
    primLiber = i;
}

int MD::CreazaNod(TElem elem) {
    /// Complexitate Teta(1)

    int i = aloca();
    e[i] = elem;
    urm[i] = -1;
    prev[i] = -1;
    return i;
}

TValoare MD::CeaMaiFrecventaValoare() const{
    /// Teta(n^2)

    if (this->vid())
        return NULL_TVALOARE;
    vector<TValoare> valori;
    auto it = this->iterator();
    while(it.valid()){
        auto elem = it.element();
        auto val = elem.second;
        valori.push_back(val);
        it.urmator();
    }

    int n = valori.size();
    int maxi = 0;
    TValoare maxival;
    for(int i = 0 ; i < n-1 ; i ++ ){
        TValoare val = valori[i];
        int cont = 1;
        for ( int j = i+1 ; j < n ; j ++ ) {
            if (valori[i] == valori[i+1])
                cont++;
        }
        if ( cont > maxi){
            maxi = cont;
            maxival = val;
        }
    }
    return maxival;
}