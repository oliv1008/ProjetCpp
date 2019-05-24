#ifndef CCALCULMATRICIEL
#define CCALCULMATRICIEL

// Codes exceptions
#define ERR_TAILLE	4

template <class MType> class CCalculMatriciel
{
	public:
		
		static CMatrice<MType>& CMAAddition(CMatrice<MType> MATA, CMatrice<MType> MATB);
		static CMatrice<MType>& CMASoustraction(CMatrice<MType> MATA, CMatrice<MType> MATB);
		static CMatrice<MType>& CMAProduit(CMatrice<MType> MATA, CMatrice<MType> MATB);
		static CMatrice<MType> CMAExtraireSousMatrice(CMatrice<MType> MATA, unsigned int uiIndiceLigneMATA, unsigned int uiIndiceColonneMATA);
};

#include "header/CException.h"
#include "src/CCalculMatriciel.cpp"

#endif
