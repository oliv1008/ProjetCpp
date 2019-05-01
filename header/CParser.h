#ifndef CPARSER 
#define CPARSER

#include <iostream>
#include <fstream>
#include "header/CException.h"

using namespace std;

//Inclusion cyclique entre CMatrice et CParser
//On prédéfini CMatrice pour le compilateur
template<typename MType>
class CMatrice;

class CParser {

	private :

		

	public :

		static void PARSeparateString(char cToken, char* pcStr1, char* pcStr2); 
		static bool PARIsStringEqual(const char* pccStr1, const char* pccStr2);
		static bool PARIsStringANumericalValue(const char * pcStr);

		//Obligé de mettre la déclaration dans le .h car template de méthode
		/************************************************
		**** Nom: PARParserMatrice                   ****
		*************************************************
		****                                         ****
		*************************************************
		**** Précondition: pcChemin pointe vers une  ****
		****    chaine de caractère valide (terminée ****
		****    par '\0')                            ****
		**** Entrée: pcChemin : const char *         ****
		****    uiNbLignes : unsigned int &          ****
		****    uiNbColonnes : unsigned int &        ****
		****    pMTPMatrice : MType** &              ****
		****                                         ****
		**** Entraîne: Si pcChemin est un chemin     ****
		****    valide vers un fichier et ce fichier ****
		****    respecte le format demandé :         ****
		****      uiNbLigne, uiNbColonnes et         ****
		****    pMTPMatrice sont initialisées aux    ****
		****    valeurs de la matrice contenu dans   ****
		****    le fichier                           ****
		****    Sinon :                              ****
		****      La fonction renvoie une exception  ****
		**** Sortie: Rien                            ****
		************************************************/
		template <class MType> static void PARParserMatrice(const char * pcChemin, unsigned int &uiNbLignes, unsigned int &uiNbColonnes, MType** &pMTPMatrice)
		{
			ifstream fichier(pcChemin, ios::in);  // on ouvre le fichier en lecture
 
			if(fichier)  // si l'ouverture a réussi
			{       
				// instructions
				char ligne[256];
				char resultat[256];
				
				//On récupère le type de la matrice
				fichier >> ligne;
				//cout << ligne << endl;
				CParser::PARSeparateString('=', ligne, resultat);
				
				//On vérifie qu'il est valide
				if (!CParser::PARIsStringEqual(ligne, "TypeMatrice") || !CParser::PARIsStringEqual(resultat, "double"))
				{
					CException ErrFormat(ERR_FORMAT);
					throw ErrFormat;
				}
				
				//On récupère le nombre de lignes
				fichier >> ligne;
				//cout << ligne << endl;
				CParser::PARSeparateString('=', ligne, resultat);
				
				if (!CParser::PARIsStringEqual(ligne, "NBLignes"))
				{
					CException ErrFormat(ERR_FORMAT);
					throw ErrFormat;
				}
				else if (!CParser::PARIsStringANumericalValue(resultat))
				{
					CException ErrNumerique(ERR_NUMERIQUE);
					throw ErrNumerique;
				}

				uiNbLignes = atoi(resultat);
				
				//On récupère le nombre de colonnes
				fichier >> ligne;
				//cout << ligne << endl;
				CParser::PARSeparateString('=', ligne, resultat);
				
				if (!CParser::PARIsStringEqual(ligne, "NBColonnes"))
				{
					CException ErrFormat(ERR_FORMAT);
					throw ErrFormat;
				}
				else if (!CParser::PARIsStringANumericalValue(resultat))
				{
					CException ErrNumerique(ERR_NUMERIQUE);
					throw ErrNumerique;
				}
				
		
				uiNbColonnes = atoi(resultat);
			
				//On saute la ligne "Matrice=["
				fichier >> ligne;
				//cout << ligne << endl;
				if (!CParser::PARIsStringEqual(ligne, "Matrice=["))
				{
					CException ErrFormat(ERR_FORMAT);
					throw ErrFormat;
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
						//cout << ligne << endl;
						if (CParser::PARIsStringEqual(ligne, "]"))
						{
							CException ErrDimension(ERR_DIMENSION);
							throw ErrDimension;
						}
						else if (!CParser::PARIsStringANumericalValue(ligne))
						{
							CException ErrNumerique(ERR_NUMERIQUE);
							throw ErrNumerique;
						}
						
						pMTPMatrice[uiBoucleL][uiBoucleC] = atof(ligne);
					}
				}
				
				fichier >> ligne;
				//cout << ligne << endl;
				if (!CParser::PARIsStringEqual(ligne, "]"))
				{
					CException ErrDimension(ERR_DIMENSION);
					throw ErrDimension;
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