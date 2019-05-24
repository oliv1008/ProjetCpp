#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

/*********** METHODES **********/

/***********************************************************************************
**** Nom: CMAAddition		                                                    ****
************************************************************************************
**** Fonction d'addition entre 2 matrices                                       ****
************************************************************************************
**** Précondition: taille de A = taille de B (sinon lève une exception)         ****
**** Entrée: MATA : CMatrice<MType>, MATB : CMatrice<MType>                     ****
**** Entraîne: Le calcul de MATA + MATB										    ****
**** Sortie: CMatrice<MType>&													****
***********************************************************************************/
template <class MType>
CMatrice<MType>& CCalculMatriciel<MType>::CMAAddition(CMatrice<MType> MATA, CMatrice<MType> MATB)
{
	// Gestion exception (tailles des matrices différentes)
	if(MATA.MATLireNbColonnes() != MATB.MATLireNbColonnes() || MATA.MATLireNbLignes() != MATB.MATLireNbLignes())
	{
		CException ErrTaille(ERR_TAILLE);
		throw ErrTaille;
	}
	
	// Allocation d'une nouvelle matrice
	CMatrice<MType> *MATNouveau = new CMatrice<MType>(MATA.MATLireNbLignes(), MATA.MATLireNbColonnes());
	
	// Calcul des valeurs
	for(unsigned int uiBoucleL = 0; uiBoucleL < MATNouveau->MATLireNbLignes(); uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < MATNouveau->MATLireNbColonnes(); uiBoucleC++)
		{
			MATNouveau->MATModifierElement(uiBoucleL, uiBoucleC, MATA.MATLireElement(uiBoucleL, uiBoucleC) + MATB.MATLireElement(uiBoucleL, uiBoucleC));
		}
	}
	
	return *MATNouveau;
}

/***********************************************************************************
**** Nom: CMASoustraction		                                                ****
************************************************************************************
**** Fonction de soustraction entre 2 matrices                                  ****
************************************************************************************
**** Précondition: taille de A = taille de B (sinon lève une exception)         ****
**** Entrée: MATA : CMatrice<MType>, MATB : CMatrice<MType>                     ****
**** Entraîne: Le calcul de MATA - MATB										    ****
**** Sortie: CMatrice<MType>&													****
***********************************************************************************/
template <class MType>
CMatrice<MType>& CCalculMatriciel<MType>::CMASoustraction(CMatrice<MType> MATA, CMatrice<MType> MATB)
{
	// Gestion exception (tailles des matrices différentes)
	if(MATA.MATLireNbColonnes() != MATB.MATLireNbColonnes() || MATA.MATLireNbLignes() != MATB.MATLireNbLignes())
	{
		CException ErrTaille(ERR_TAILLE);
		throw ErrTaille;
	}
	
	// Allocation d'une nouvelle matrice
	CMatrice<MType> *MATNouveau = new CMatrice<MType>(MATA.MATLireNbLignes(), MATA.MATLireNbColonnes());
	
	// Calcul des valeurs
	for(unsigned int uiBoucleL = 0; uiBoucleL < MATNouveau->MATLireNbLignes(); uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < MATNouveau->MATLireNbColonnes(); uiBoucleC++)
		{
			MATNouveau->MATModifierElement(uiBoucleL, uiBoucleC, MATA.MATLireElement(uiBoucleL, uiBoucleC) - MATB.MATLireElement(uiBoucleL, uiBoucleC));
		}
	}
	
	return *MATNouveau;
}

/***********************************************************************************
**** Nom: CMAProduit			                                                ****
************************************************************************************
**** Fonction de produit entre 2 matrices		                                ****
************************************************************************************
**** Précondition: lignes de MATB = colonnes de A (sinon lève une exception)    ****
**** Entrée: MATA : CMatrice<MType>, MATB : CMatrice<MType>                     ****
**** Entraîne: Le calcul de MATA * MATB										    ****
**** Sortie: CMatrice<MType>&													****
***********************************************************************************/
template <class MType>
CMatrice<MType>& CCalculMatriciel<MType>::CMAProduit(CMatrice<MType> MATA, CMatrice<MType> MATB)
{
	// Gestion exception (taille des matrices incohérente)
	if(MATB.MATLireNbLignes() != MATA.MATLireNbColonnes())
	{
		CException ErrTaille(ERR_TAILLE);
		throw ErrTaille;
	}
	
	// Allocation d'une nouvelle matrice (Taille = Lignes de A * Colonnes de B)
	CMatrice<MType> *MATNouveau = new CMatrice<MType>(MATA.MATLireNbLignes(), MATB.MATLireNbColonnes());
	
	// Calcul des valeurs
	for(unsigned int uiBoucleL = 0; uiBoucleL < MATNouveau->MATLireNbLignes(); uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < MATNouveau->MATLireNbColonnes(); uiBoucleC++)
		{
			for(unsigned int uiBoucleK = 0; uiBoucleK < MATA.MATLireNbColonnes(); uiBoucleK++)
			{
				double dResultat = MATNouveau->MATLireElement(uiBoucleL, uiBoucleC) + MATA.MATLireElement(uiBoucleL, uiBoucleK) * MATB.MATLireElement(uiBoucleK, uiBoucleC);
				// Arrondi du resultat, dans les cas où on obtient un nombre proche de 0 (du type e-300)
				if(dResultat < 0.000000000001)	
					dResultat = 0;
				
				MATNouveau->MATModifierElement(uiBoucleL, uiBoucleC, dResultat);
			}
		}
	}
	
	return *MATNouveau;
}

template <class MType>
CMatrice<MType>& CCalculMatriciel<MType>::CMACalculMatriceCofacteurs(CMatrice<MType> MATMatrice)
{
	unsigned int uiBoucleL = 0, uiBoucleC = 0;
	
	// Gestion exceptions (matrice non carrée)
	if(MATMatrice.MATLireNbLignes() != MATMatrice.MATLireNbColonnes())
	{
		CException ErrTaille(ERR_TAILLE);
		throw ErrTaille;
	}
	
	// Allocation d'une nouvelle matrice
	CMatrice<MType> *MATNouveau = new CMatrice<MType>(MATMatrice.MATLireNbLignes(), MATMatrice.MATLireNbColonnes());
	
	// Calcul des valeurs
	for(uiBoucleL = 0; uiBoucleL < MATNouveau->MATLireNbLignes(); uiBoucleL++)
	{
		for(uiBoucleC = 0; uiBoucleC < MATNouveau->MATLireNbColonnes(); uiBoucleC++)
		{
			// C(i,j) = (-1)^(i+j) * det(sousMatrice(i, j))
			MATNouveau->MATModifierElement(uiBoucleL, uiBoucleC, pow((-1), uiBoucleL + uiBoucleC + 2) * CMAExtraireSousMatrice(MATMatrice, uiBoucleL, uiBoucleC).MATCalculDeterminant());
		}
	}
	
	return *MATNouveau;
}

template <class MType>
CMatrice<MType> CCalculMatriciel<MType>::CMAExtraireSousMatrice(CMatrice<MType> MATA, unsigned int uiIndiceLigneMATA, unsigned int uiIndiceColonneMATA)
{
	CMatrice<double> MATB(MATA.MATLireNbLignes() - 1, MATA.MATLireNbColonnes() - 1);
	unsigned int uiIndiceLigneMATB = 0;
	unsigned int uiIndiceColonneMATB = 0;
	unsigned int uiBoucleL = 0;
	unsigned int uiBoucleC = 0;
	
	// Gestion exception (indices invalides)
	if(uiIndiceLigneMATA > MATA.MATLireNbLignes() || uiIndiceColonneMATA > MATA.MATLireNbColonnes())
	{
		CException ErrIndices(ERR_INDICES);
		throw ErrIndices;
	}
	
	if (uiIndiceLigneMATA == 0)
	{
			uiBoucleL = 1;
	}
	for (uiBoucleL = uiBoucleL; uiBoucleL < MATA.MATLireNbLignes(); uiBoucleL++)
	{
		for (uiBoucleC = 0; uiBoucleC < MATA.MATLireNbColonnes(); uiBoucleC++)
		{
			if (uiBoucleC != uiIndiceColonneMATA)
			{
				MATB.MATModifierElement(uiIndiceLigneMATB, uiIndiceColonneMATB, MATA.MATLireElement(uiBoucleL, uiBoucleC));
				uiIndiceColonneMATB++;
			}
		}
		
		if ((uiBoucleL + 1) == uiIndiceLigneMATA)
		{
			uiBoucleL++;
		}
	
		uiIndiceLigneMATB++;
		uiIndiceColonneMATB = 0;
	}
	
	return MATB;
}
/*******************************/