#include <iostream>
#include <cstdlib>

using namespace std;

/*********** METHODES **********/
template <class MType>
CMatrice<MType>& CCalculMatriciel<MType>::CMAAddition(CMatrice<MType> MATA, CMatrice<MType> MATB)
{
	// Gestion exception (divison par zero)
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

template <class MType>
CMatrice<MType>& CCalculMatriciel<MType>::CMASoustraction(CMatrice<MType> MATA, CMatrice<MType> MATB)
{
	// Gestion exception (divison par zero)
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

template <class MType>
CMatrice<MType>& CCalculMatriciel<MType>::CMAProduit(CMatrice<MType> MATA, CMatrice<MType> MATB)
{
	// Gestion exception (divison par zero)
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
