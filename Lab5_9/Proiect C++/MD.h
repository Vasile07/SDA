#pragma once
#include<vector>
#include<utility>
#define NMAX 400000
#define NULL_TVALOARE NULL

using namespace std;

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

class IteratorMD;

class MD
{
	friend class IteratorMD;

private:
	/* aici e reprezentarea */
    int prim, ultim;
    int primLiber;
    int lungime;
    TElem* e = new TElem[NMAX];
    int* urm = new int[NMAX];
    int* prev = new int[NMAX];

    int aloca();
    void dealoca(int i);

    int CreazaNod(TElem elem);

public:
	// constructorul implicit al MultiDictionarului
	MD();

	// adauga o pereche (cheie, valoare) in MD	
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MD 
	int dim() const;

	//verifica daca MultiDictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe MD
	IteratorMD iterator() const;

	// destructorul MultiDictionarului	
	~MD();

    TValoare CeaMaiFrecventaValoare() const;

};

