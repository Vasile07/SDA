#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie &c): col(c){
    this->iterator = 0;
}

void IteratorColectie::prim() {
    /***
     * Teta(1)
     */
	this->iterator = 0;
}


void IteratorColectie::urmator() {
    /***
     * Teta(1)
     */
    if (!this->valid())
        throw ;
    this->iterator ++;
}


bool IteratorColectie::valid() const {
    /***
     * Teta(1)
     */
	return  this->iterator >= 0 && this->iterator < col.dim();
}



TElem IteratorColectie::element() const {
    /***
     * Teta(1)
     */
	if ( !this->valid())
	    return -1;
    return (TElem)col.elemente[this->iterator];
}
