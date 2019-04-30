#include <iostream>
#include <cstdlib>

#include "header/CException.h"

using namespace std;

/********* CONSTRUCTEURS *********/

/** Constructeur de confort **/
CException::CException(unsigned int uiEXCErreur){
	this->uiEXCErreur = uiEXCErreur;
}

/*********************************/

/********** ACCESSEURS **********/ 
unsigned int CException::EXCLireErreur()
{
	return uiEXCErreur;
}

void CException::EXCModifierErreur(unsigned int uiEXCErreur)
{
	this->uiEXCErreur = uiEXCErreur;
}
/********************************/

/*********** METHODES **********/
void CException::EXCAfficherErreur()
{
	switch(uiEXCErreur)
	{
		case ERR_CONSTRUCTEUR : cerr << "Erreur zero div" << endl; break;
		case ERR_INDICES : cerr << "Erreur zero div" << endl; break;
		case ERR_TAILLE : cerr << "Erreur zero div" << endl; break;
		case ERR_ZERO_DIV : cerr << "Erreur zero div" << endl; break;
	}
}
/********************************/
