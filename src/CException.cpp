#include <iostream>
#include <cstdlib>

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
