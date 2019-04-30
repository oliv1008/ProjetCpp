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
	
	matC = matA + matB;
	
	macC.MATAfficherMatrice();
	
	return 0;
}

