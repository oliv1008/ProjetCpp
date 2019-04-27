#include <iostream>
#include <cstdlib>

using namespace std;

/*********** METHODES **********/   /*
template <class MType>
CMatrice<MType>& CCalculMatriciel<MType>::operator+(CMatrice<MType> MATB)
{
	// Allocation d'une nouvelle matrice
	CMatrice<MType> *MATNouveau = new CMatrice<MType>(this->MATLireNbLignes(), this->MATLireNbColonnes());
	
	// Calcul des valeurs
	for(unsigned int uiBoucleL = 0; uiBoucleL < MATNouveau.MATLireNbLignes(); uiBoucleL++)
	{
		for(unsigned int uiBoucleC = 0; uiBoucleC < MATNouveau.MATLireNbColonnes(); uiBoucleC++)
		{
			MATNouveau->MATModifierElement(uiBoucleL, uiBoucleC, this->MATLireElement(uiBoucleL, uiBoucleC) + MATB->MATLireElement(uiBoucleL, uiBoucleC));
		}
	}
	
	return *MATNouveau;
}*/
/*******************************/

