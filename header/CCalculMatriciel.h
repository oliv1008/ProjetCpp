#ifndef CCALCULMATRICIEL
#define CCALCULMATRICIEL

//#include <header/CMatrice.h>

template <class MType> class CCalculMatriciel
{
	public:
		
		CMatrice<MType>& CMAAddition(CMatrice<MType> MATA, CMatrice<MType> MATB);
		CMatrice<MType>& CMASoustraction(CMatrice<MType> MATA, CMatrice<MType> MATB);
		CMatrice<MType>& CMAProduit(CMatrice<MType> MATA, CMatrice<MType> MATB);
		
};

#include "src/CCalculMatriciel.cpp"

#endif
