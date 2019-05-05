#ifndef CMATRICECPP
#define CMATRICECPP

#include <iostream>
#include <cstdlib>

#include "header/CCalculMatriciel.h"

#define DISPLAY_PRECISION 3		// Précision (nombre de chiffres après la virgule) de l'affichage de matrices

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
	pMATMTPMatrice = (MType **)malloc(sizeof(MType *));
	pMATMTPMatrice[0] = (MType *)calloc(1, sizeof(MType));
}

/** Constructeur de confort **/
template <class MType> 
CMatrice<MType>::CMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{
	// Initialisation lignes et colonnes
	MATModifierNbLignes(uiNbLignes);
	MATModifierNbColonnes(uiNbColonnes);
	
	// Allocation mémoire
	pMATMTPMatrice = (MType **)malloc(uiNbLignes * sizeof(MType *));
	for(unsigned int uiBoucle = 0; uiBoucle < uiNbLignes; uiBoucle++)
	{
		pMATMTPMatrice[uiBoucle] = (MType *)calloc(uiNbColonnes, sizeof(MType));
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
	pMATMTPMatrice = (MType **)malloc(uiMATNbLignes * sizeof(MType *));
	for(unsigned int uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
	{
		pMATMTPMatrice[uiBoucle] = (MType *)malloc(uiMATNbColonnes * sizeof(MType));
	}
	
	// Recopie des valeurs
	for(unsigned int uiBoucleL = 0; uiBoucleL < uiMATNbLignes; uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < uiMATNbColonnes; uiBoucleC++)
		{
			MATModifierElement(uiBoucleL, uiBoucleC, MATCopie.MATLireElement(uiBoucleL, uiBoucleC));
		}
	}
}

/** Constructeur depuis un fichier **/
template <class MType> 
CMatrice<MType>::CMatrice(const char *pcChemin)
{
	unsigned int uiNbLignes = 0;
	unsigned int uiNbColonnes = 0;
	MType **pMTPMatrice = nullptr;
	
	CParser::PARParserMatrice(pcChemin, uiNbLignes, uiNbColonnes, pMTPMatrice);
		
	// Initialisation lignes et colonnes
	MATModifierNbLignes(uiNbLignes);
	MATModifierNbColonnes(uiNbColonnes);
		
	// Allocation mémoire
	this->pMATMTPMatrice = (MType **)malloc(uiNbLignes * sizeof(MType *));
	for(unsigned int uiBoucle = 0; uiBoucle < uiNbLignes; uiBoucle++)
	{
		this->pMATMTPMatrice[uiBoucle] = (MType *)malloc(uiNbColonnes * sizeof(MType));
	}
		
	MATModifierMatrice(pMTPMatrice);

}
/********************************/

/********** DESTRUCTEUR *********/ 
template <class MType>
CMatrice<MType>::~CMatrice()
{
	for(unsigned int uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++)
	{
		free(pMATMTPMatrice[uiBoucle]);
	}
	free(pMATMTPMatrice);
}
/********************************/

/********** ACCESSEURS **********/ 
template <class MType> 
unsigned int CMatrice<MType>::MATLireNbLignes()
{
	return uiMATNbLignes;
}

/***********************************************************************************
**** Nom: MATModifierNbLignes                                                   ****
************************************************************************************
**** Accesseur de l'argument uiNbLignes                                         ****
************************************************************************************
**** Précondition: uiNbLignes != 0 (sinon lève une exception)                   ****
**** Entrée: uiNbLignes : unsigned int                                          ****
**** Entraîne: Le changement de l'argument uiNbLignes de la matrice qui appelle ****
**** Sortie: Rien                                                               ****
***********************************************************************************/
template <class MType> 
void CMatrice<MType>::MATModifierNbLignes(unsigned int uiNbLignes)
{
	// Gestion exception (dimension nulle)
	if(uiNbLignes == 0)
	{
		CException ErrConstructeur(ERR_CONSTRUCTEUR);
		throw ErrConstructeur;
	}
	
	uiMATNbLignes = uiNbLignes;
}
		
template <class MType> 
unsigned int CMatrice<MType>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
}

/***********************************************************************************
**** Nom: MATModifierNbColonnes                                                 ****
************************************************************************************
**** Accesseur de l'argument uiNbColonnes                                       ****
************************************************************************************
**** Précondition: uiNbColonnes != 0 (sinon lève une exception)                 ****
**** Entrée: uiNbColonnes : unsigned int                                        ****
**** Entraîne: Le changement de l'argument uiNbColonnes de la matrice qui app.  ****
**** Sortie: Rien                                                               ****
***********************************************************************************/
template <class MType> 
void CMatrice<MType>::MATModifierNbColonnes(unsigned int uiNbColonnes)
{
	// Gestion exception (dimension nulle)
	if(uiNbColonnes == 0)
	{
		CException ErrConstructeur(ERR_CONSTRUCTEUR);
		throw ErrConstructeur;
	}
	
	uiMATNbColonnes = uiNbColonnes;
}
		
template <class MType>
MType CMatrice<MType>::MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne)
{
	// Gestion exception (indices invalides)
	if(uiIndiceLigne >= uiMATNbLignes || uiIndiceColonne >= uiMATNbColonnes)
	{
		CException ErrConstructeur(ERR_INDICES);
		throw ErrConstructeur;
	}
	
	return pMATMTPMatrice[uiIndiceLigne][uiIndiceColonne];
}

/***********************************************************************************
**** Nom: MATModifierElement                                                    ****
************************************************************************************
**** Permet de modifier un élément unique de la matrice                         ****
************************************************************************************
**** Précondition: uiIndiceLigne < uiNbLignes et uiIndiceColonne < uiNbColonnes ****
**** Entrée: uiIndiceLigne : unsigned int,                                      ****
****		 uiIndiceColonne : unsigned int,				                    ****
****		 MTPElement : MType													**** 
**** Entraîne: Le changement de pMTPMatrice[uiIndiceLigne][uiIndiceColonne]     ****
**** Sortie: Rien                                                               ****
***********************************************************************************/
template <class MType>
void CMatrice<MType>::MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MType MTPElement)
{
	// Gestion exception (indices invalides)
	if(uiIndiceLigne > uiMATNbLignes || uiIndiceColonne > uiMATNbColonnes)
	{
		CException ErrIndices(ERR_INDICES);
		throw ErrIndices;
	}
	
	pMATMTPMatrice[uiIndiceLigne][uiIndiceColonne] = MTPElement;
}

/***********************************************************************************
**** Nom: MATReallouerMatrice                                                   ****
************************************************************************************
**** Permet de réallouer une matrice existante à une nouvelle taille            ****
************************************************************************************
**** Précondition: uiNbLignes > 0 et uiNbColonnes > 0 (sinon exception)			****
**** Entrée: uiNbLignes : unsigned int, uiNbColonnes : unsigned int             ****
**** Entraîne: Une réallocation du tableau 2D contenu dans la matrice           ****
**** Sortie: Rien                                                               ****
***********************************************************************************/
template <class MType>
void CMatrice<MType>::MATReallouerMatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes)
{	
	// Gestion exception (dimension nulle)
	if(uiNbLignes == 0 || uiNbColonnes == 0)
	{
		CException ErrConstructeur(ERR_CONSTRUCTEUR);
		throw ErrConstructeur;
	}
	
	// Libération de la mémoire
	for(unsigned int uiBoucle = 0; uiBoucle < this->MATLireNbLignes(); uiBoucle++)
	{
		free(pMATMTPMatrice[uiBoucle]);
	}
	free(pMATMTPMatrice);
	
	// Allocation mémoire
	pMATMTPMatrice = (MType **)malloc(uiNbLignes * sizeof(MType *));
	
	for(unsigned int uiBoucle = 0; uiBoucle < uiNbLignes; uiBoucle++)
	{
		pMATMTPMatrice[uiBoucle] = (MType *)calloc(uiNbColonnes, sizeof(MType));
	}
}

/***********************************************************************************
**** Nom: MATModifierMatrice                                                    ****
************************************************************************************
**** Permet de modifier une matrice depuis un tableau 2D                        ****
************************************************************************************
**** Précondition: pMTPMatriceArg est de la meme taille que la matrice qui app. ****
**** Entrée: pMTPMatriceArg : MType **                                          ****
**** Entraîne: Copie élément par élément de pMTPMatriceArg dans la matrice      ****
**** Sortie: Rien                                                               ****
***********************************************************************************/
template <class MType>
void CMatrice<MType>::MATModifierMatrice(MType **pMTPMatriceArg)
{
	
	for(unsigned int uiBoucleL = 0; uiBoucleL < uiMATNbLignes; uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < uiMATNbColonnes; uiBoucleC++)
		{
			MATModifierElement(uiBoucleL, uiBoucleC, pMTPMatriceArg[uiBoucleL][uiBoucleC]);
		}
	}
}
/*******************************/ 



/*********** METHODES **********/

/***********************************************************************************
**** Nom: MATAfficher                                                           ****
************************************************************************************
**** Affiche une matrice à l'écran                                              ****
************************************************************************************
**** Précondition: Rien                                                         ****
**** Entrée: Rien                                                               ****
**** Entraîne: L'affichage de la matrice qui appelle la fonction                ****
**** Sortie: Rien                                                               ****
***********************************************************************************/
template <class MType> 
void CMatrice<MType>::MATAfficher()
{
	cout.precision(DISPLAY_PRECISION);
	for(unsigned int uiBoucleL = 0; uiBoucleL < uiMATNbLignes; uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < uiMATNbColonnes; uiBoucleC++)
		{
			cout << pMATMTPMatrice[uiBoucleL][uiBoucleC] << " ";
		}
		cout << endl;
	}
}

/***********************************************************************************
**** Nom: operator=                                                             ****
************************************************************************************
**** Surcharge de l'opérateur = entre 2 matrices                                ****
************************************************************************************
**** Précondition: Rien                                                         ****
**** Entrée: MATMatrice : CMatrice<MType>&                                      ****
**** Entraîne: La recopie de MATMatrice dans la matrice qui appelle la fonction ****
**** Sortie: CMatrice<MType>&                                                   ****
***********************************************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator=(CMatrice<MType>& MATMatrice)
{	
	// Réallocation mémoire
	MATReallouerMatrice(MATMatrice.MATLireNbLignes(), MATMatrice.MATLireNbColonnes());
	
	// Initialisation lignes et colonnes
	MATModifierNbLignes(MATMatrice.MATLireNbLignes());
	MATModifierNbColonnes(MATMatrice.MATLireNbColonnes());
	
	// Recopie des valeurs
	for(unsigned int uiBoucleL = 0; uiBoucleL < uiMATNbLignes; uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < uiMATNbColonnes; uiBoucleC++)
		{
			MATModifierElement(uiBoucleL, uiBoucleC, MATMatrice.MATLireElement(uiBoucleL, uiBoucleC));
		}
	}
	
	return *this;
}

/***********************************************************************************
**** Nom: operator*                                                             ****
************************************************************************************
**** Surcharge de l'opérateur * entre une matrice et un double                  ****
************************************************************************************
**** Précondition: Rien                                                         ****
**** Entrée: dNombre : double                                                   ****
**** Entraîne: Le calcul de (dNombre * la matrice qui appelle la fonction)      ****
**** Sortie: CMatrice<MType>&                                                   ****
***********************************************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(double dNombre)
{
	// Recopie de la matrice
	CMatrice<MType> *MATNouveau = new CMatrice<MType>(*this);
	
	// Calcul des valeurs
	for(unsigned int uiBoucleL = 0; uiBoucleL < uiMATNbLignes; uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < uiMATNbColonnes; uiBoucleC++)
		{
			MATNouveau->MATModifierElement(uiBoucleL, uiBoucleC, dNombre*MATNouveau->MATLireElement(uiBoucleL, uiBoucleC));
		}
	}
	
	return *MATNouveau;
}

/***********************************************************************************
**** Nom: operator/                                                             ****
************************************************************************************
**** Surcharge de l'opérateur / entre une matrice et un double                  ****
************************************************************************************
**** Précondition: dNombre != 0 (sinon exception levée)                         ****
**** Entrée: dNombre : double                                                   ****
**** Entraîne: Le calcul de (la matrice qui appelle la fonction / dNombre)      ****
**** Sortie: CMatrice<MType>&                                                   ****
***********************************************************************************/
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
	for(unsigned int uiBoucleL = 0; uiBoucleL < uiMATNbLignes; uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < uiMATNbColonnes; uiBoucleC++)
		{
			MATNouveau->MATModifierElement(uiBoucleL, uiBoucleC, MATNouveau->MATLireElement(uiBoucleL, uiBoucleC)/dNombre);
		}
	}
	
	return *MATNouveau;
}

/***********************************************************************************
**** Nom: MATTransposer                                                         ****
************************************************************************************
**** Fonction utilisée pour transposer une matrice                              ****
************************************************************************************
**** Précondition: Rien                                                         ****
**** Entrée: Rien                                                               ****
**** Entraîne: La transposition de la matrice qui appelle la fonction           ****
**** Sortie: CMatrice<MType>&                                                   ****
***********************************************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::MATTransposer()
{
	// Recopie de la matrice
	CMatrice<MType> *MATNouveau = new CMatrice<MType>(uiMATNbColonnes, uiMATNbLignes);

	// Calcul des valeurs
	for(unsigned int uiBoucleL = 0; uiBoucleL < uiMATNbColonnes; uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < uiMATNbLignes; uiBoucleC++)
		{
			MATNouveau->MATModifierElement(uiBoucleL, uiBoucleC, MATLireElement(uiBoucleC, uiBoucleL));
		}
	}
	
	return *MATNouveau;
}

/***********************************************************************************
**** Nom: operator+                                                             ****
************************************************************************************
**** Surcharge de l'opérateur + entre 2 matrices                                ****
**** Appelle la fonction CMAAddition, se référer à la doc de cette fonction     ****
***********************************************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator+(CMatrice<MType> MATB)
{
	return CCalculMatriciel<MType>::CMAAddition(*this, MATB);
}

/***********************************************************************************
**** Nom: operator-                                                             ****
************************************************************************************
**** Surcharge de l'opérateur - entre 2 matrices                                ****
**** Appelle la fonction CMASoustraction, se référer à la doc de cette fonction ****
***********************************************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator-(CMatrice<MType> MATB)
{
	return CCalculMatriciel<MType>::CMASoustraction(*this, MATB);
}

/***********************************************************************************
**** Nom: operator*                                                             ****
************************************************************************************
**** Surcharge de l'opérateur * entre 2 matrices                                ****
**** Appelle la fonction CMAProduit, se référer à la doc de cette fonction      ****
***********************************************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(CMatrice<MType> MATB)
{
	return CCalculMatriciel<MType>::CMAProduit(*this, MATB);
}
/*******************************/

#endif