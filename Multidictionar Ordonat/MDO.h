#pragma once

#include <vector>

typedef int TCheie;
typedef int TValoare;
#define NIL -1
#define STERS -100
#include <utility>

typedef struct Nod
{
	TCheie c;
	std::vector< TValoare > valori;
};

typedef std::pair<TCheie, TValoare> TElem;

using namespace std;

class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);

class MDO {
	friend class IteratorMDO;
private:
	int radacina;
	Nod* element;
	int* stang;
	int* drept;

	int primLiber;
	int* urmator;
	int capacitate;
	int lungime;

	Relatie rel;

	void redimensionare();

public:

	// constructorul implicit al MultiDictionarului Ordonat
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	int removeElement(int radacina, TElem e, bool& removed);

	int maxim(int radacina);
	//returneaza numarul de perechi (cheie, valoare) din MDO 
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile in ordine in raport cu relatia de ordine
	IteratorMDO iterator() const;

	// destructorul 	
	~MDO();

	vector<TCheie> multimeaCheilor() const;
};