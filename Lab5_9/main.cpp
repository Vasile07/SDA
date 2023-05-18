#include <iostream>
#include <cassert>
#include "Teste/TestScurt.h"
#include "Teste/TestExtins.h"
#include "Proiect C++/MD.h"
#include "Proiect C++/IteratorMD.h"
using namespace std;

void test_MultimeaCheilor(){
    MD dictionar;

    for ( int i  = 0 ; i < 9 ; i ++ ){
        if ( i  % 2 == 0){
            dictionar.adauga(i, 2);
            dictionar.adauga(i, 2);
        }
        else{
            dictionar.adauga(i,1);
            dictionar.adauga(i,1);
        }
    }

    assert(dictionar.CeaMaiFrecventaValoare() == 2);

    MD d_nou;
    assert(d_nou.CeaMaiFrecventaValoare() == NULL_TVALOARE);
}

int main() {

	testAll();
	testAllExtins();
	cout<<"End";

    test_MultimeaCheilor();
    return 0;
}
