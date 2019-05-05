#ifndef CMATRICE
#define CMATRICE

// Codes exceptions
#define ERR_CONSTRUCTEUR 	1
#define ERR_INDICES			2
#define ERR_ZERO_DIV		3

template <class MType> class CMatrice
{

	private :

		unsigned int uiMATNbLignes;
		unsigned int uiMATNbColonnes;
		MType **pMATMTPMatrice = nullptr;

	public :

		// Constructeurs
		CMatrice();
		CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes);
		CMatrice(CMatrice<MType>& MATCopie);
		CMatrice(const char *pcChemin);

		// Destructeur
		~CMatrice();

		// Accesseurs
		unsigned int MATLireNbLignes();
		void MATModifierNbLignes(unsigned int uiNbLignes);
		
		unsigned int MATLireNbColonnes();
		void MATModifierNbColonnes(unsigned int uiNbColonnes);
		
		MType MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne);
		void MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MType MTPElement);

		// Méthodes et surcharges d'opérateurs
		CMatrice<MType>& operator=(CMatrice<MType>& MATMatrice);
		CMatrice<MType>& operator*(double dNombre);
		CMatrice<MType>& operator/(double dNombre);
		
		CMatrice<MType>& operator+(CMatrice<MType> MATB);
		CMatrice<MType>& operator-(CMatrice<MType> MATB);
		CMatrice<MType>& operator*(CMatrice<MType> MATB);
		
		CMatrice<MType>& MATTransposer();
	
		void MATAfficher();
		
		void MATReallouerMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes);
		void MATModifierMatrice(MType ** pMTPMatriceArg);
};

#include "header/CParser.h"
#include "header/CException.h"
#include "header/CCalculMatriciel.h"
#include "src/CMatrice.cpp"

#endif