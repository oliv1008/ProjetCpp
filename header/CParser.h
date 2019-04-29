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

		static void PARSeparateString(char cToken, const char* src, char* dst); 
		static bool PARStringCompare(const char* str1, const char* str2);

		//Obligé de mettre la déclaration dans le .h car template de méthode
		template <class MType> static void PARParserMatrice(const char * pcChemin, CMatrice<MType>& mat)
		{
			ifstream fichier(pcChemin, ios::in);  // on ouvre le fichier en lecture
 
			if(fichier)  // si l'ouverture a réussi
			{       
				// instructions
				char ligne[256];
				char resultat[256];
				
				//On récupère le type de la matrice
				fichier >> ligne;
				CParser::PARSeparateString('=', ligne, resultat);
				//On vérifie qu'il est valide
				if (CParser::PARStringCompare(resultat, "double"))
				{
					cout << "Type de matrice valide" << endl;
					//On récupère le nombre de lignes
					fichier >> ligne;
					CParser::PARSeparateString('=', ligne, resultat);
					mat.MATModifierNbLignes(atoi(resultat));
					
					//On récupère le nombre de colonnes
					fichier >> ligne;
					CParser::PARSeparateString('=', ligne, resultat);
					mat.MATModifierNbColonnes(atoi(resultat));
					
					//On saute la ligne "Matrice=["
					fichier >> ligne;
					
					//On remplit la matrice
					mat.MATReallouerMatrice(mat.MATLireNbLignes(), mat.MATLireNbColonnes());
					for (unsigned int uiBoucleL = 0; uiBoucleL < mat.MATLireNbLignes(); uiBoucleL++)
					{
						for (unsigned int uiBoucleC = 0; uiBoucleC < mat.MATLireNbColonnes(); uiBoucleC++)
						{
							//On récupère l'élement
							fichier >> ligne;
							mat.MATModifierElement(uiBoucleL, uiBoucleC, atof(ligne));
						}
					}
					
					cout << "mat.NbLignes = " << mat.MATLireNbLignes() << endl;
					cout << "mat.NbColonnes = " << mat.MATLireNbColonnes() << endl;
					mat.MATAfficher();
				}
				else
				{
					cout << "Type de matrice non valide" << endl;
				}
				
				fichier.close();  // on ferme le fichier
			}
			else  // sinon
			{
				cerr << "Impossible d'ouvrir le fichier !" << endl;
			}
			
		}
	  
};

#endif