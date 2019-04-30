#include <iostream>
#include "header/CParser.h"
#include "header/CMatrice.h"
#include "header/CCalculMatriciel.h"

using namespace std;

int main(int argc, char **argv)
{
	// Allocation de argc-1 matrices
	cout << "### Allocation de " << argc-1 << " matrices..." << endl;
	CMatrice<double> **pMATTable = (CMatrice<double> **)malloc((argc-1)*sizeof(CMatrice<double> *));
	
	// Création des matrices à partir des fichiers passés en arguments
	cout << "### Création des " << argc-1 << " matrices..." << endl;
	for(int iBoucle = 1; iBoucle < argc; iBoucle++)
	{
		pMATTable[iBoucle-1] = new CMatrice<double>(argv[iBoucle]);
		cout << " > M" << iBoucle << " = \n" << endl;
		pMATTable[iBoucle-1]->MATAfficher();
		cout << endl;
	}
	
	
	// Demande de c
	double c;
	cout << "### Saississez une valeur : ";
	cin >> c;
	
	// Multiplications par c
	cout << "\n=== Multiplications par " << c << " ===" << endl;
	for(int iBoucle = 0; iBoucle < argc-1; iBoucle++)
	{
		cout << "\n > M" << iBoucle+1 << " * " << c << " = \n" << endl;
		(*pMATTable[iBoucle] * c).MATAfficher();
	}
	
	// Divisions par c
	cout << "\n=== Divisions par " << c << " ===" << endl;
	for(int iBoucle = 0; iBoucle < argc-1; iBoucle++)
	{
		cout << "\n > M" << iBoucle+1 << " / " << c << " = \n" << endl;
		try {
			(*pMATTable[iBoucle] / c).MATAfficher();
		} catch(CException EXCErreur) {
			EXCErreur.EXCAfficherErreur();
		}
	}
	
	CMatrice<double> MATTemp(pMATTable[0]->MATLireNbLignes(), pMATTable[0]->MATLireNbColonnes());
	
	// Sommes des matrices
	cout << "\n=== Somme des matrices ===" << endl;
	
	try 
	{
		cout << "\n > M1";
		MATTemp = *pMATTable[0];
		for(int iBoucle = 1; iBoucle < argc-1; iBoucle++)
		{
			cout << " + M" << iBoucle+1;
			MATTemp = MATTemp + *pMATTable[iBoucle];
		}
		cout << " = \n" << endl;
		MATTemp.MATAfficher();
	} 
	catch(CException EXCErreur) 
	{
		EXCErreur.EXCAfficherErreur();
	}
	
	// Alternance addition/soustraction
	cout << "\n=== Alternance addition/soustraction ===" << endl;
	
	try 
	{
		cout << "\n > M1";
		MATTemp = *pMATTable[0];
		for(int iBoucle = 1; iBoucle < argc-1; iBoucle++)
		{
			if(iBoucle % 2 == 1)	// Indice impair
			{
				cout << " + M" << iBoucle+1;
				MATTemp = MATTemp + *pMATTable[iBoucle];
			}
			else if(iBoucle % 2 == 0)					// Indice pair
			{
				cout << " - M" << iBoucle+1;
				MATTemp = MATTemp - *pMATTable[iBoucle];
			}
		}
		cout << " = \n" << endl;
		MATTemp.MATAfficher();
	}
	catch(CException EXCErreur) 
	{
		EXCErreur.EXCAfficherErreur();
	}
	
	// Produits
	cout << "\n=== Produits ===" << endl;
	
		CMatrice<double> result;
		
	for(int iBoucle1 = 0; iBoucle1 < argc-1; iBoucle1++)
	{
		for(int iBoucle2 = 0; iBoucle2 < argc-1; iBoucle2++)
		{
			cout << "\n > M" << iBoucle1+1 << " * M" << iBoucle2+1 << " = \n" << endl;
			try 
			{
				result = (*pMATTable[iBoucle1]) * (*pMATTable[iBoucle2]);
				result.MATAfficher();
			}
			catch(CException EXCErreur) 
			{
				EXCErreur.EXCAfficherErreur();
			}
		}
	}
	
	
	
	return 0;
}

