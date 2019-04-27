#include <iostream>
#include "header/CMatrice.h"
#include "header/CCalculMatriciel.h"

using namespace std;

int main(int argc, char **argv)
{
	/*cout << "==== test (vide) =====" << endl;
	
	CMatrice<int> test(3,3);
	test.MATAfficher();
	
	cout << "=== test (remplie) ===" << endl;
	
	test.MATModifierElement(0, 0, 1);
	test.MATModifierElement(1, 1, 2);
	test.MATModifierElement(2, 2, 3);
	test.MATAfficher();
	
	cout << "==== copie de test ===" << endl;
	
	CMatrice<int> copie(test);
	copie.MATAfficher();
	
	cout << "==== truc = copie ====" << endl;
	
	CMatrice<int> truc;
	truc = copie;
	truc.MATAfficher();
	
	CMatrice<int> & RefTruc = truc;
	cout << "Création d'une reference sur truc" << endl;
	cout << "RefTruc.MATAfficher()" << endl;
	RefTruc.MATAfficher();
	RefTruc.MATModifierElement(0, 0, 10);
	cout << "RefTruc.MATModifierElement(0, 0, 10)" << endl;
	cout << "RefTruc.MATAfficher()" << endl;
	RefTruc.MATAfficher();
	
	cout << "====== copie = truc * 5 ======" << endl;
	
	copie = truc * 5;
	copie.MATAfficher();
	
	cout << "====== copie = truc / 5 ======" << endl;
	
	copie = copie / 5;
	copie.MATAfficher();
	
	cout << "=== copie remplissage ===" << endl;
	
	copie.MATModifierElement(0, 0, 1);
	copie.MATModifierElement(0, 1, 2);
	copie.MATModifierElement(0, 2, 3);
	copie.MATModifierElement(1, 0, 4);
	copie.MATModifierElement(1, 1, 5);
	copie.MATModifierElement(1, 2, 6);
	copie.MATModifierElement(2, 0, 7);
	copie.MATModifierElement(2, 1, 8);
	copie.MATModifierElement(2, 2, 9);
	copie.MATAfficher();
	
	cout << "====== copie = copie.transposer() ======" << endl;
	
	copie = copie.MATTransposer();
	copie.MATAfficher();*/
	
	/*CMatrice<int> matA(2, 2);
	CMatrice<int> matB(2, 2);
	CMatrice<int> matC;
	matA.MATModifierElement(0, 0, 1);
	matA.MATModifierElement(0, 1, 2);
	matA.MATModifierElement(1, 0, 3);
	matA.MATModifierElement(1, 1, 4);
	matB = matA * 2;
	matB.MATModifierElement(0, 0, 0);
	cout << "matA = " << endl;
	matA.MATAfficher();
	cout << "matB = " << endl;
	matB.MATAfficher();
	matC = matA - matB;
	cout << "matA - matB = " << endl;
	matC.MATAfficher();
	matC = matB - matA;
	cout << "matB - matA = " << endl;
	matC.MATAfficher();
	cout << "==================" << endl;
	cout << "matA * matB = " << endl;
	matC = matA * matB;
	matC.MATAfficher();
	cout << "matB * matA = " << endl;
	matC = matB * matA;
	matC.MATAfficher();*/
	
	CMatrice<int> matA(1, 2);
	CMatrice<int> matB(2, 3);
	CMatrice<int> matC;
	matA.MATModifierElement(0, 0, 1);
	matA.MATModifierElement(0, 1, 2);
	matB.MATModifierElement(0, 0, 1);
	matB.MATModifierElement(0, 1, 2);
	matB.MATModifierElement(0, 2, 3);
	matB.MATModifierElement(1, 0, 4);
	matB.MATModifierElement(2, 1, 5);
	matB.MATModifierElement(3, 2, 6);
	matC = matA * matB;
	matC.MATAfficher();
	
	
	return 0;
}

