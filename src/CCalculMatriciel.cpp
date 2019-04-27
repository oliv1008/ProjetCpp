#include <iostream>
#include <cstdlib>

using namespace std;

/*********** METHODES **********/
template <class MType>
CMatrice<MType>& CCalculMatriciel<MType>::CMAAddition(CMatrice<MType> MATA, CMatrice<MType> MATB)
{
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
	if(MATB.MATLireNbLignes() != MATA.MATLireNbColonnes())
	{
		cout << "grosse erreur mamène" << endl;
		exit(0);	// erreur si taille de B incorrecte
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
				MATNouveau->MATModifierElement(uiBoucleL, uiBoucleC, MATNouveau->MATLireElement(uiBoucleL, uiBoucleC) +
				MATA.MATLireElement(uiBoucleL, uiBoucleK) * MATB.MATLireElement(uiBoucleK, uiBoucleC));
				// en gros là je fais C(i,j) = C(i,j) + A(i, k) * B(k, j)
			}
		}
	}
	
	return *MATNouveau;
}
/*******************************/
