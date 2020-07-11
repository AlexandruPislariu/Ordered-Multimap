#include "IteratorMDO.h"
#include "MDO.h"

IteratorMDO::IteratorMDO(const MDO& d) : dict(d) {
	
	curent = dict.radacina;
}

void IteratorMDO::prim() 
{/* Complexitate O(h) */
	while (curent != NIL)
	{
		s.push(curent);
		curent = dict.stang[curent];
	}
	if (!s.empty())
	{
		curent = s.top();
		s.pop();
	}
	else
		curent = NIL;
}

void IteratorMDO::urmator() 
{/* 
	Complexitate O(h) 
	Parcurgere INORDINE
*/
	if (dict.drept[curent] != NIL)
	{
		curent = dict.drept[curent];
		while (curent != NIL)
		{
			s.push(curent);
			curent = dict.stang[curent];
		}
	}
	if (!s.empty())
	{
		curent = s.top();
		s.pop();
	}
	else
		curent = NIL;
}

bool IteratorMDO::valid() const {
	
	if (curent != NIL)
		return true;

	return false;
}

TElem IteratorMDO::element() const {
	
	return pair <TCheie, TValoare>(dict.element[curent].c, dict.element[curent].valori[0]);
}

