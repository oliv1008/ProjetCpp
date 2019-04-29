#ifndef CMATRICECPP
#define CMATRICECPP

#include <iostream>
#include <cstdlib>
#include "header/CCalculMatriciel.h"

using namespace std;

/********* CONSTRUCTEURS *********/

/** Constructeur par défaut **/
template <class MType> 
CMatrice<MType>::CMatrice()
{
	// Initialisation lignes et colonnes
	MATModifierNbLignes(1);
	MATModifierNbColonnes(1);
	
	// Allocation mémoire
	pMTPMatrice = (MType **)malloc(sizeof(MType *));
	pMTPMatrice[0] = (MType *)malloc(sizeof(MType));
}

/** Constructeur de confort **/
template <class MType> 
CMatrice<MType>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	// Initialisation lignes et colonnes
	MATModifierNbLignes(uiNbLignes);
	MATModifierNbColonnes(uiNbColonnes);
	
	// Allocation mémoire
	pMTPMatrice = (MType **)malloc(uiNbLignes * sizeof(MType *));
	for(unsigned int uiBoucle = 0; uiBoucle < uiNbLignes; uiBoucle++)
	{
		pMTPMatrice[uiBoucle] = (MType *)malloc(uiNbColonnes * sizeof(MType));
	}
}

/** Constructeur de recopie **/
template <class MType> 
CMatrice<MType>::CMatrice(CMatrice<MType>& MATCopie)
{
	// Initialisation lignes et colonnes
	MATModifierNbLignes(MATCopie.MATLireNbLignes());
	MATModifierNbColonnes(MATCopie.MATLireNbColonnes());
	
	// Allocation mémoire
	pMTPMatrice = (MType **)malloc(uiNbLignes * sizeof(MType *));
	for(unsigned int uiBoucle = 0; uiBoucle < uiNbLignes; uiBoucle++)
	{
		pMTPMatrice[uiBoucle] = (MType *)malloc(uiNbColonnes * sizeof(MType));
	}
	
	// Recopie des valeurs
	for(unsigned int uiBoucleL = 0; uiBoucleL < uiNbLignes; uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < uiNbColonnes; uiBoucleC++)
		{
			MATModifierElement(uiBoucleL, uiBoucleC, MATCopie.MATLireElement(uiBoucleL, uiBoucleC));
		}
	}
}

/** Constructeur depuis un fichier **/
template <class MType> 
CMatrice<MType>::CMatrice(const char *pcChemin)
{
	CParser::PARParserMatrice(pcChemin, *this);
}

/********************************/



/********** ACCESSEURS **********/ 
template <class MType> 
unsigned int CMatrice<MType>::MATLireNbLignes()
{
	return uiNbLignes;
}

template <class MType> 
void CMatrice<MType>::MATModifierNbLignes(unsigned int uiNbLignes)
{
	// Gestion exception (divison par zero)
	if(uiNbLignes == 0)
	{
		CException ErrConstructeur(ERR_CONSTRUCTEUR);
		throw ErrConstructeur;
	}
	
	this->uiNbLignes = uiNbLignes;
}
		
template <class MType> 
unsigned int CMatrice<MType>::MATLireNbColonnes()
{
	return uiNbColonnes;
}

template <class MType> 
void CMatrice<MType>::MATModifierNbColonnes(unsigned int uiNbColonnes)
{
	// Gestion exception (divison par zero)
	if(uiNbColonnes == 0)
	{
		CException ErrConstructeur(ERR_CONSTRUCTEUR);
		throw ErrConstructeur;
	}
	
	this->uiNbColonnes = uiNbColonnes;
}
		
template <class MType>
MType CMatrice<MType>::MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne)
{
	return pMTPMatrice[uiIndiceLigne][uiIndiceColonne];
}

template <class MType>
void CMatrice<MType>::MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MType MTPElement)
{
	// Gestion exception (indices invalides)
	if(uiIndiceLigne > uiNbLignes || uiIndiceColonne > uiNbColonnes)
	{
		CException ErrIndices(ERR_INDICES);
		throw ErrIndices;
	}
	
	pMTPMatrice[uiIndiceLigne][uiIndiceColonne] = MTPElement;
}

template <class MType>
void CMatrice<MType>::MATReallouerMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{	
	// Allocation mémoire
	pMTPMatrice = (MType **)realloc(pMTPMatrice, uiNbLignes * sizeof(MType *));
	
	for(unsigned int uiBoucle = 0; uiBoucle < uiNbLignes; uiBoucle++)
	{
		pMTPMatrice[uiBoucle] = (MType *)realloc(pMTPMatrice[uiBoucle], uiNbColonnes * sizeof(MType));
	}
}

/*******************************/ 



/*********** METHODES **********/
template <class MType> 
void CMatrice<MType>::MATAfficher()
{
	for(unsigned int uiBoucleL = 0; uiBoucleL < uiNbLignes; uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < uiNbColonnes; uiBoucleC++)
		{
			cout << pMTPMatrice[uiBoucleL][uiBoucleC] << " ";
		}
		cout << endl;
	}
}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator=(CMatrice<MType>& MATMatrice)
{
	// Initialisation lignes et colonnes
	MATModifierNbLignes(MATMatrice.MATLireNbLignes());
	MATModifierNbColonnes(MATMatrice.MATLireNbColonnes());
	
	// Réallocation mémoire
	MATReallouerMatrice(uiNbLignes, uiNbColonnes);
	
	// Recopie des valeurs
	for(unsigned int uiBoucleL = 0; uiBoucleL < uiNbLignes; uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < uiNbColonnes; uiBoucleC++)
		{
			MATModifierElement(uiBoucleL, uiBoucleC, MATMatrice.MATLireElement(uiBoucleL, uiBoucleC));
		}
	}
	
	return *this;
}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(double dNombre)
{
	// Recopie de la matrice
	CMatrice<MType> *MATNouveau = new CMatrice<MType>(*this);
	
	// Calcul des valeurs
	for(unsigned int uiBoucleL = 0; uiBoucleL < uiNbLignes; uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < uiNbColonnes; uiBoucleC++)
		{
			MATNouveau->MATModifierElement(uiBoucleL, uiBoucleC, dNombre*MATNouveau->MATLireElement(uiBoucleL, uiBoucleC));
		}
	}
	
	return *MATNouveau;
}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator/(double dNombre)
{
	// Gestion exception (divison par zero)
	if(dNombre == 0)
	{
		CException ErrZeroDiv(ERR_ZERO_DIV);
		throw ErrZeroDiv;
	}
	
	// Recopie de la matrice
	CMatrice<MType> *MATNouveau = new CMatrice<MType>(*this);
	
	// Calcul des valeurs
	for(unsigned int uiBoucleL = 0; uiBoucleL < uiNbLignes; uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < uiNbColonnes; uiBoucleC++)
		{
			MATNouveau->MATModifierElement(uiBoucleL, uiBoucleC, MATNouveau->MATLireElement(uiBoucleL, uiBoucleC)/dNombre);
		}
	}
	
	return *MATNouveau;
}

template <class MType>
CMatrice<MType>& CMatrice<MType>::MATTransposer()
{
	// Recopie de la matrice
	CMatrice<MType> *MATNouveau = new CMatrice<MType>(uiNbColonnes, uiNbLignes);

	// Calcul des valeurs
	for(unsigned int uiBoucleL = 0; uiBoucleL < uiNbColonnes; uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < uiNbLignes; uiBoucleC++)
		{
			MATNouveau->MATModifierElement(uiBoucleL, uiBoucleC, this->MATLireElement(uiBoucleC, uiBoucleL));
		}
	}
	
	return *MATNouveau;
}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator+(CMatrice<MType> MATB)
{
	return CCalculMatriciel<MType>::CMAAddition(*this, MATB);
}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator-(CMatrice<MType> MATB)
{
	return CCalculMatriciel<MType>::CMASoustraction(*this, MATB);
}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(CMatrice<MType> MATB)
{
	return CCalculMatriciel<MType>::CMAProduit(*this, MATB);
}
/*******************************/

#endif