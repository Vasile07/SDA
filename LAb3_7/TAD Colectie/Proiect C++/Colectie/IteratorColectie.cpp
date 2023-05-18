#include "IteratorColectie.h"
#include "Colectie.h"
#include <stdexcept>

IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	this->curent = c.prim;
}

void IteratorColectie::prim() {
    this->curent = this->col.prim;
}


void IteratorColectie::urmator() {
	/* de adaugat */
    this->curent = this->curent->urmator();
}


bool IteratorColectie::valid() const {
	/* de adaugat */
    if(this->curent == nullptr)
        return false;
	return true;
}



TElem IteratorColectie::element() const {
	/* de adaugat */
    if(this->valid())
        return this->curent->element();
    throw std::invalid_argument("Iterator invalid!");
}
