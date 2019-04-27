#ifndef CMATRICE
#define CMATRICE

template <class MType> class CMatrice
{

	private :

		unsigned int uiNbLignes;
		unsigned int uiNbColonnes;
		MType **pMTPMatrice;

	public :

		// Constructeurs
		CMatrice();
		CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes);
		CMatrice(CMatrice<MType>& MATCopie);
		CMatrice(const char *pcChemin);

		// Destructeur
		//~CMatrice();

		// Accesseurs
		unsigned int MATLireNbLignes();
		void MATModifierNbLignes(unsigned int uiNbLignes);
		
		unsigned int MATLireNbColonnes();
		void MATModifierNbColonnes(unsigned int uiNbColonnes);
		
		MType MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne);
		void MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MType MTPElement);
		void MATModifierMatrice(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne);

		// Méthodes et surcharges d'opérateurs
		CMatrice<MType>& operator=(CMatrice<MType>& MATMatrice);
		CMatrice<MType>& operator*(double dNombre);
		CMatrice<MType>& operator/(double dNombre);
		
		CMatrice<MType>& MATTransposer();
		
		void MATAfficher();
		
		// A CHOISIR SI ON MET CA ICI OU DANS "CALCUL MATRICIEL"
		CMatrice<MType>& operator+(CMatrice<MType> MATB);
		CMatrice<MType>& operator-(CMatrice<MType> MATB);
		CMatrice<MType>& operator*(CMatrice<MType> MATB);
};

#include <header/CParser.h>
#include "src/CMatrice.cpp"

#endif