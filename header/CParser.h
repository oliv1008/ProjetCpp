#ifndef CPARSER 
#define CPARSER

#include <iostream>
#include <fstream>

#include "header/CException.h"

// Codes exceptions
#define ERR_FORMAT 			5
#define ERR_NUMERIQUE 		6
#define ERR_DIMENSION 		7
#define ERR_FICHIER			8

using namespace std;

// Inclusion cyclique entre CMatrice et CParser
// On prédéfinit CMatrice pour le compilateur
//template<typename MType>
//class CMatrice;

class CParser {

	public :

		static void PARSeparateString(char cToken, char* pcStr1, char* pcStr2); 
		static bool PARIsStringEqual(const char* pccStr1, const char* pccStr2);
		static bool PARIsStringANumericalValue(const char * pcStr);

		// Obligé de mettre la déclaration de PARParserMatrice dans le .h car c'est un template de méthode
		
		/***********************************************************************************
		**** Nom: PARParserMatrice		                                                ****
		************************************************************************************
		**** Fonction utilisée pour lire une matrice depuis un fichier texte            ****
		************************************************************************************
		**** Précondition: pcChemin pointe vers une chaine de caractère valide,         ****
		****	           représentant un fichier existant, qui respecte le bon format	**** 
		**** Entrée: pcChemin : const char*, uiNbLignes : unsigned int &                ****
		****		 uiNbColonnes : unsigned int &, pMTPMatrice : MType** &				**** 
		**** Entraîne: l'initialisation de uiNbLignes, uiNbColonnes	 et pMTPMatrice	aux	****
		****		   valeurs contenues dans le fichier								**** 
		**** Sortie: Rien																****
		***********************************************************************************/
		template <class MType> 
		static void PARParserMatrice(const char * pcChemin, unsigned int &uiNbLignes, unsigned int &uiNbColonnes, MType** &pMTPMatrice)
		{
			ifstream fichier(pcChemin, ios::in);  // On ouvre le fichier en lecture seule
 
			if(fichier)  // Si l'ouverture a réussi
			{       
				char ligne[256];
				char resultat[256];
				
				// On récupère le type de la matrice
				fichier >> ligne;
				CParser::PARSeparateString('=', ligne, resultat);
				
				// On vérifie qu'il est valide
				if (!CParser::PARIsStringEqual(ligne, "TypeMatrice") || !CParser::PARIsStringEqual(resultat, "double"))
				{
					CException ErrFormat(ERR_FORMAT);
					throw ErrFormat;
				}
				
				// On récupère le nombre de lignes
				fichier >> ligne;
				CParser::PARSeparateString('=', ligne, resultat);
				
				// On vérifie qu'il est valide
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
				
				// On récupère le nombre de colonnes
				fichier >> ligne;
				CParser::PARSeparateString('=', ligne, resultat);
				
				// On vérifie qu'il est valide
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
			
				// On vérifie que la ligne "Matrice=[" est valide
				fichier >> ligne;
				if (!CParser::PARIsStringEqual(ligne, "Matrice=["))
				{
					CException ErrFormat(ERR_FORMAT);
					throw ErrFormat;
				}
				
	
				// On remplit la matrice (tableau 2D)
				pMTPMatrice = (MType **)malloc(uiNbLignes * sizeof(MType *));
				for(unsigned int uiBoucle = 0; uiBoucle < uiNbLignes; uiBoucle++)
				{
					pMTPMatrice[uiBoucle] = (MType *)malloc(uiNbColonnes * sizeof(MType));
				}
			
				for (unsigned int uiBoucleL = 0; uiBoucleL < uiNbLignes; uiBoucleL++)
				{
					for (unsigned int uiBoucleC = 0; uiBoucleC < uiNbColonnes; uiBoucleC++)
					{
						// On récupère l'élement
						fichier >> ligne;

						// On vérifie qu'il est valide
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
				if (!CParser::PARIsStringEqual(ligne, "]"))
				{
					CException ErrDimension(ERR_DIMENSION);
					throw ErrDimension;
				}

				fichier.close();  // On ferme le fichier
			}
			else // Impossible d'ouvrir le fichier
			{
				CException ErrFichier(ERR_FICHIER);
				throw ErrFichier;
			}
		}
};

#endif