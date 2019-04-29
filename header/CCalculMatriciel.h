#ifndef CCALCULMATRICIEL
#define CCALCULMATRICIEL

#define ERR_TAILLE 4

#include "header/CMatrice.h"

template <class MType> class CCalculMatriciel
{
	public:
		
		static CMatrice<MType>& CMAAddition(CMatrice<MType> MATA, CMatrice<MType> MATB);
		static CMatrice<MType>& CMASoustraction(CMatrice<MType> MATA, CMatrice<MType> MATB);
		static CMatrice<MType>& CMAProduit(CMatrice<MType> MATA, CMatrice<MType> MATB);
		
};

#include "src/CCalculMatriciel.cpp"

#endif
