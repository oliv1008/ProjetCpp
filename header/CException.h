#ifndef CEXCEPTION
#define CEXCEPTION

#include <iostream>

#define ERR_CONSTRUCTEUR 	1
#define ERR_INDICES			2
#define ERR_ZERO_DIV		3
#define ERR_TAILLE 			4

class CException 
{
	private :
	
		unsigned int uiEXCErreur;
		
	public :
	
		// Constructeurs
		CException(unsigned int uiEXCErreur);
		
		// Accesseurs
		unsigned int EXCLireErreur();
		void EXCModifierErreur(unsigned int uiEXCErreur);
		
		// Méthodes
		void EXCAfficherErreur();
};

#endif