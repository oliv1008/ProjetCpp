#include <iostream>
#include <cstdlib>

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
				if(dResultat < 0.0000000001)	
					dResultat = 0;
				
				MATNouveau->MATModifierElement(uiBoucleL, uiBoucleC, dResultat);
			}
		}
	}
	
	return *MATNouveau;
}
/*******************************/
