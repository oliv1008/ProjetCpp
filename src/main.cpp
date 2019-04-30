#include <iostream>
#include "header/CParser.h"
#include "header/CMatrice.h"
#include "header/CCalculMatriciel.h"

using namespace std;

int main(int argc, char **argv)
{
	CMatrice<double> A("../fichier.txt");
	/*if (CParser::PARIsStringANumericalValue("5"))
	{
		cout << "5 est une valeur numérique" << endl;
	}
	else
	{
		cout << "5 n'est pas une valeur numérique" << endl;
	}
	
	if (CParser::PARIsStringANumericalValue("500"))
	{
		cout << "500 est une valeur numérique" << endl;
	}
	else
	{
		cout << "500 n'est pas une valeur numérique" << endl;
	}
	
	if (CParser::PARIsStringANumericalValue("5 "))
	{
		cout << "5  est une valeur numérique" << endl;
	}
	else
	{
		cout << "5  n'est pas une valeur numérique" << endl;
	}
	
	if (CParser::PARIsStringANumericalValue("a"))
	{
		cout << "a est une valeur numérique" << endl;
	}
	else
	{
		cout << "a n'est pas une valeur numérique" << endl;
	}*/
	
	return 0;
}

