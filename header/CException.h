#ifndef CEXCEPTION
#define CEXCEPTION

#include <iostream>

// Exceptions dans CMatrice.cpp
#define ERR_CONSTRUCTEUR 	1
#define ERR_INDICES			2
#define ERR_ZERO_DIV		3

// Exceptions dans CCalculMatriciel.cpp
#define ERR_TAILLE 			4

// Exceptions dans CParser.cpp
#define ERR_FORMAT 			5
#define ERR_NUMERIQUE 		6
#define ERR_DIMENSION 		7
#define ERR_FICHIER			8

class CException 
{
	private :
	
		unsigned int uiEXCErreur;
		
	public :
	
		// Constructeurs
		CException(unsigned int uiErreur);
		
		// Accesseurs
		unsigned int EXCLireErreur();
		void EXCModifierErreur(unsigned int uiErreur);
		
		// Méthodes
		void EXCAfficherErreur();
};

#endif