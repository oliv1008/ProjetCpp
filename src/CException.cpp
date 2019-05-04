#include <iostream>
#include <cstdlib>

#include "header/CException.h"

using namespace std;

/********* CONSTRUCTEURS *********/

/** Constructeur de confort **/
CException::CException(unsigned int uiErreur){
	EXCModifierErreur(uiErreur);
}

/*********************************/

/********** ACCESSEURS **********/ 
unsigned int CException::EXCLireErreur()
{
	return uiEXCErreur;
}

void CException::EXCModifierErreur(unsigned int uiErreur)
{
	uiEXCErreur = uiErreur;
}
/********************************/

/*********** METHODES **********/
void CException::EXCAfficherErreur()
{
	switch(uiEXCErreur)
	{
		case ERR_CONSTRUCTEUR : cerr << " Erreur : la taille des matrices ne peut pas être nulle" << endl; break;
		case ERR_INDICES : cerr << " Erreur : indices trop grands" << endl; break;
		case ERR_TAILLE : cerr << " Erreur : tailles des matrices incohérentes" << endl; break;
		case ERR_ZERO_DIV : cerr << " Erreur : division par zéro impossible" << endl; break;
		case ERR_FORMAT : cerr << " Erreur : format de fichier non valide" << endl; break;
		case ERR_NUMERIQUE : cerr << " Erreur : valeur non numérique" << endl; break;
		case ERR_DIMENSION : cerr << "Erreur : erreur dans la dimension de la matrice" << endl; break;
		case ERR_FICHIER : cerr << "Erreur : impossible de lire le fichier en paramètre" << endl; break;
		default : cerr << "Erreur inconnue" << endl; break;
	}
}
/********************************/
