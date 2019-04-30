#include <iostream>
#include "header/CParser.h"
#include "header/CMatrice.h"
#include "header/CCalculMatriciel.h"

using namespace std;

int main(int argc, char **argv)
{
	CMatrice<int> matA("mat1.txt");
	CMatrice<int> matB("mat2.txt");
	CMatrice<int> matC;
	
	cout << "=========" << endl;
	matC = matA + matB;
	
	matC.MATAfficher();
	
	
	/*
	// Allocation de argc-1 matrices
	cout << "### Allocation de " << argc-1 << " matrices..." << endl;
	CMatrice<double> **pMATTable = (CMatrice<double> **)malloc((argc-1)*sizeof(CMatrice<double> *));
	
	// Création des matrices à partir des fichiers passés en arguments
	cout << "### Création des " << argc-1 << " matrices..." << endl;
	for(int iBoucle = 1; iBoucle < argc; iBoucle++)
	{
		cout << " > M" << iBoucle << " = \n" << endl;
		pMATTable[iBoucle-1] = new CMatrice<double>(argv[iBoucle]);
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
	
	// Sommes des matrices
	cout << "\n=== Somme des matrices ===" << endl;
	CMatrice<double> MATTemp(pMATTable[0]->MATLireNbLignes(), pMATTable[0]->MATLireNbColonnes());
	cout << "\n > ";
	for(int iBoucle = 0; iBoucle < argc-1; iBoucle++)
	{
		cout << "M" << iBoucle+1 << " + ";
		try {
			MATTemp = MATTemp + *pMATTable[iBoucle];
		} catch(CException EXCErreur) {
			EXCErreur.EXCAfficherErreur();
		}
	}
	cout << " = \n" << endl;
	MATTemp.MATAfficher();
	
	// Alternance addition/soustraction
	cout << "\n=== Alternance addition/soustraction ===" << endl;
	cout << "\n > ";
	for(int iBoucle = 0; iBoucle < argc-1; iBoucle++)
	{
		if(iBoucle % 2 == 0)	// Indice pair
		{
			cout << "M" << iBoucle+1 << " + ";
			try {
				MATTemp = MATTemp + *pMATTable[iBoucle];
			} catch(CException EXCErreur) {
				EXCErreur.EXCAfficherErreur();
			}
		}
		else					// Indice impair
		{
			cout << "M" << iBoucle+1 << " - ";
			try {
				MATTemp = MATTemp - *pMATTable[iBoucle];
			} catch(CException EXCErreur) {
				EXCErreur.EXCAfficherErreur();
			}
		}
	}
	cout << " = " << endl;
	MATTemp.MATAfficher();
	*/
	return 0;
}

