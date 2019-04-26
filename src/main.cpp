#include <iostream>
#include "header/CMatrice.h"
#include "header/CCalculMatriciel.h"

using namespace std;

int main(int argc, char **argv)
{
	cout << "==== test (vide) =====" << endl;
	
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
	
	/*CMatrice<int> & RefTruc = truc;
	cout << "Création d'une reference sur truc" << endl;
	cout << "RefTruc.MATAfficher()" << endl;
	RefTruc.MATAfficher();
	RefTruc.MATModifierElement(0, 0, 10);
	cout << "RefTruc.MATModifierElement(0, 0, 10)" << endl;
	cout << "RefTruc.MATAfficher()" << endl;
	RefTruc.MATAfficher();*/
	
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
	copie.MATAfficher();
	
	return 0;
}

