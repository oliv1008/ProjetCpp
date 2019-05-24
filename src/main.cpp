#include <iostream>
#include "header/CParser.h"
#include "header/CMatrice.h"
#include "header/CCalculMatriciel.h"

using namespace std;

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		cerr << " Erreur : le programme doit être lancé avec au moins un fichier en paramètre" << endl;
		return -1;
	}
	
	/***** Allocation des matrices *********************************************/
	cout << "### Allocation de " << argc-1 << " matrices..." << endl;
	CMatrice<double> **pMATTable = (CMatrice<double> **)malloc((argc-1)*sizeof(CMatrice<double> *));
	
	/***** Création des matrices à partir des fichiers passés en arguments *****/
	cout << "### Création des " << argc-1 << " matrices...\n" << endl;
	for(int iBoucle = 1; iBoucle < argc; iBoucle++)
	{
		try 
		{
			pMATTable[iBoucle-1] = new CMatrice<double>(argv[iBoucle]);
		}
		catch(CException EXCErreur) 
		{
			// Erreur dans le parser = erreur critique (on arrête l'exécution du programme)
			switch(EXCErreur.EXCLireErreur())
			{
				case ERR_FORMAT : cerr << " Erreur : format de fichier non valide" << endl; break;
				case ERR_NUMERIQUE : cerr << " Erreur : valeur non numérique" << endl; break;
				case ERR_DIMENSION : cerr << "Erreur : erreur dans la dimension de la matrice" << endl; break;
				case ERR_FICHIER : cerr << "Erreur : impossible de lire le fichier en paramètre" << endl; break;
				default : cerr << "Erreur inconnue" << endl; break;
			}
			return -1;
		}
		
		cout << " > M" << iBoucle << " = \n" << endl;
		pMATTable[iBoucle-1]->MATAfficher();
		cout << endl;
	}
	
	cout << "\n===== Matrices des cofacteurs =====\n" << endl;
	
	int iBoucle = 0;
	for(iBoucle = 0; iBoucle < argc - 1; iBoucle++)
	{
		try
		{
			CCalculMatriciel<double>::CMACalculMatriceCofacteurs(*pMATTable[iBoucle]).MATAfficher();
		}
		catch(CException EXCErreur)
		{
			switch(EXCErreur.EXCLireErreur())
			{
				case ERR_CONSTRUCTEUR : cerr << " Erreur : taille nulle" << endl; break;
				case ERR_INDICES : cerr << " Erreur : indices incohérents" << endl; break;
				case ERR_TAILLE : cerr << "Erreur : taille de matrice non valide" << endl; break;
				default : cerr << "Erreur inconnue" << endl; break;
			}
			return -1;
		}
	}
	
	cout << "\n===================================\n" << endl;
	
	return 0;
}
