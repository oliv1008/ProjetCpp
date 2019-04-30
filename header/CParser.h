#ifndef CPARSER 
#define CPARSER

#include <iostream>
#include <fstream>

using namespace std;

//Inclusion cyclique entre CMatrice et CParser
//On prédéfini CMatrice pour le compilateur
template<typename MType>
class CMatrice;

class CParser {

	private :

		// rien ma gueule

	public :

		static void PARSeparateString(char cToken, char* src, char* dst); 
		static bool PARIsStringEqual(const char* str1, const char* str2);
		static bool PARIsStringANumericalValue(const char * pcStr);

		//Obligé de mettre la déclaration dans le .h car template de méthode
		template <class MType> static void PARParserMatrice(const char * pcChemin, CMatrice<MType>& mat)
		{
			ifstream fichier(pcChemin, ios::in);  // on ouvre le fichier en lecture
 
			if(fichier)  // si l'ouverture a réussi
			{       
				// instructions
				char ligne[256];
				char resultat[256];
				unsigned int uiNbLignes = 0;
				unsigned int uiNbColonnes = 0;
				MType ** pMTPMatrice = nullptr;
				
				//On récupère le type de la matrice
				fichier >> ligne;
				cout << ligne << endl;
				CParser::PARSeparateString('=', ligne, resultat);
				
				//On vérifie qu'il est valide
				if (!CParser::PARIsStringEqual(ligne, "TypeMatrice"))
				{
					cout << "Pas ecris \"TypeMatrice\" (erreur de format de fichier)" << endl;
					cout << "throw exception" << endl;
				}
				else if (!CParser::PARIsStringEqual(resultat, "double"))
				{
					cout << "erreur dans le type de la matrice" << endl;
					cout << "throw exception" << endl;
				}
				
				//On récupère le nombre de lignes
				fichier >> ligne;
				cout << ligne << endl;
				CParser::PARSeparateString('=', ligne, resultat);
				
				if (!CParser::PARIsStringEqual(ligne, "NBLignes"))
				{
					cout << "Pas ecris \"NBLignes\" (erreur de format de fichier)" << endl;
					cout << "throw exception" << endl;
				}
				else if (!CParser::PARIsStringANumericalValue(resultat))
				{
					cout << "erreur valeur pas numerique" << endl;
					cout << "throw exception" << endl;
				}

				uiNbLignes = atoi(resultat);
				
				//On récupère le nombre de colonnes
				fichier >> ligne;
				cout << ligne << endl;
				CParser::PARSeparateString('=', ligne, resultat);
				
				if (!CParser::PARIsStringEqual(ligne, "NBColonnes"))
				{
					cout << "Pas ecris \"NBColonnes\" (erreur de format de fichier)" << endl;
					cout << "throw exception" << endl;
				}
				else if (!CParser::PARIsStringANumericalValue(resultat))
				{
					cout << "erreur valeur pas numerique" << endl;
					cout << "throw exception" << endl;
				}
				
		
				uiNbColonnes = atoi(resultat);
			
				//On saute la ligne "Matrice=["
				fichier >> ligne;
				cout << ligne << endl;
				if (!CParser::PARIsStringEqual(ligne, "Matrice=["))
				{
					cout << "Pas ecris \"Matrice=[\"" << endl;
					cout << "throw exception" << endl;
				}
				
	
				//On remplit la matrice
				pMTPMatrice = (MType **)malloc(uiNbLignes * sizeof(MType *));
				for(unsigned int uiBoucle = 0; uiBoucle < uiNbLignes; uiBoucle++)
				{
					pMTPMatrice[uiBoucle] = (MType *)malloc(uiNbColonnes * sizeof(MType));
				}
			
				for (unsigned int uiBoucleL = 0; uiBoucleL < uiNbLignes; uiBoucleL++)
				{
					for (unsigned int uiBoucleC = 0; uiBoucleC < uiNbColonnes; uiBoucleC++)
					{
						//On récupère l'élement
						fichier >> ligne;
						cout << ligne << endl;
						if (CParser::PARIsStringEqual(ligne, "]"))
						{
							cout << "erreur dimension matrice" << endl;
							cout << "throw exception" << endl;
						}
						else if (!CParser::PARIsStringANumericalValue(ligne))
						{
							cout << "element pas une valeur numerique" << endl;
							cout << "throw exception" << endl;
						}
						
						pMTPMatrice[uiBoucleL][uiBoucleC] = atof(ligne);
					}
				}
				
				fichier >> ligne;
				cout << ligne << endl;
				if (!CParser::PARIsStringEqual(ligne, "]"))
				{
					cout << "erreur dimension matrice" << endl;
					cout << "throw exception" << endl;
				}
				
				mat.MATModifierNbLignes(uiNbLignes);
				mat.MATModifierNbColonnes(uiNbColonnes);
				mat.MATModifierMatrice(uiNbLignes, uiNbColonnes, pMTPMatrice);
				
				cout << "matrice creee" << endl;
				cout << "mat.NbLignes = " << mat.MATLireNbLignes() << endl;
				cout << "mat.NbColonnes = " << mat.MATLireNbColonnes() << endl;
				mat.MATAfficher();

				fichier.close();  // on ferme le fichier
			}
			else  // sinon
			{
				cerr << "Impossible d'ouvrir le fichier !" << endl;
			}
		}
};

#endif