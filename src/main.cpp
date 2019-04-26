#include <iostream>
#include "header/CMatrice.h"

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
	
	cout << "====== truc * 5 ======" << endl;
	
	copie = truc * 5;
	copie.MATAfficher();
	
	return 0;
}

