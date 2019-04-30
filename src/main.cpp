#include <iostream>
#include "header/CParser.h"
#include "header/CMatrice.h"
#include "header/CCalculMatriciel.h"

using namespace std;

int main(int argc, char **argv)
{
	// Allocation de argc-1 matrices
	CMatrice<double> **pMATTable = (CMatrice<double> **)malloc((argc-1)*sizeof(CMatrice<double> *));
	for(int iBoucle = 0; iBoucle < argc-1; iBoucle++)
	{
		pMATTable[iBoucle] = (CMatrice<double> *)malloc(sizeof(CMatrice<double>));
	}
	cout << "### Allocation de " << argc-1 << " matrices..." << endl;
	
	// Création des matrices à partir des fichiers passés en arguments
	for(int iBoucle = 1; iBoucle < argc; iBoucle++)
	{
		pMATTable[iBoucle-1] = new CMatrice<double>(argv[iBoucle]);
	}
	cout << "### Création des " << argc-1 << " matrices..." << endl;
	
	// Demande de c
	double c;
	cout << "### Saississez une valeur : ";
	cin >> c;
	
	// Multiplications par c
	cout << "\n === Multiplications par " << c << " ===" << endl;
	for(int iBoucle = 0; iBoucle < argc-1; iBoucle++)
	{
		cout << " > M" << iBoucle+1 << " * " << c << " = " << endl;
		(*pMATTable[iBoucle] * c).MATAfficher();
	}
	
	// Divisions par c
	cout << "\n === Divisions par " << c << " ===" << endl;
	for(int iBoucle = 0; iBoucle < argc-1; iBoucle++)
	{
		cout << " > M" << iBoucle+1 << " / " << c << " = " << endl;
		try {
			(*pMATTable[iBoucle] / c).MATAfficher();
		} catch(CException EXCErreur) {
			EXCErreur.EXCAfficherErreur();
		}
	}
	
	// Sommes des matrices
	cout << "\n === Somme des matrices ===" << endl;
	CMatrice<double> MATTemp(pMATTable[0]->MATLireNbLignes(), pMATTable[0]->MATLireNbColonnes());
	cout << " > ";
	for(int iBoucle = 0; iBoucle < argc-1; iBoucle++)
	{
		cout << "M" << iBoucle+1 << " + ";
		try {
			MATTemp = MATTemp + *pMATTable[iBoucle];
		} catch(CException EXCErreur) {
			EXCErreur.EXCAfficherErreur();
		}
	}
	cout << " = " << endl;
	MATTemp.MATAfficher();
	
	// Alternance addition/soustraction
	cout << " \n === Alternance addition/soustraction ===" << endl;
	cout << " > ";
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

	return 0;
}

