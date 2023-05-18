#pragma once

typedef int TElem;

#define M 100000
#define NULL_TELEMENT 0

class Matrice {

private:
	/* aici e reprezentarea */

    int nrLin, nrCol, primLiber;
    int* Linii = new int[M];
    int* Coloane = new int[M];
    TElem* Valoare = new TElem[M];
    int* urm = new int[M];

    /// Functia de dispersie
    int disperie( int i, int j) const;

    int nextLiber() const;

public:

	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	Matrice(int nrLinii, int nrColoane);


	//destructor
	~Matrice()= default;

	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	TElem element(int i, int j) const;


	// returnare numar linii
	int nrLinii() const;

	// returnare numar coloane
	int nrColoane() const;


	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	TElem modifica(int i, int j, TElem elem);

};







