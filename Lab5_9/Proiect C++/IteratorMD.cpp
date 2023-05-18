#include "IteratorMD.h"
#include "MD.h"

using namespace std;

IteratorMD::IteratorMD(const MD& _md): md(_md) {
	/* de adaugat */
    curent = md.prim;
}

TElem IteratorMD::element() const{
	/* de adaugat */
	return md.e[curent];
}

bool IteratorMD::valid() const {
	/* de adaugat */
    if ( curent != -1)
        return true;
	return false;
}

void IteratorMD::urmator() {
	/* de adaugat */
    curent = md.urm[curent];
}

void IteratorMD::prim() {
	/* de adaugat */
    curent = md.prim;
}

