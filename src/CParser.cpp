#include <header/CParser.h>

/**********************************************
**** Nom: PARSeparateString                ****
***********************************************
****                                       ****
***********************************************
**** Précondition: cToken est un caractère ****
****    ASCII valide                       ****
****    pcStr1 & pcStr2 sont finies par un ****
****    '\0'                               ****
**** Entrée: cToken : char                 ****
****    pcStr1 : char*                     ****
****    pcStr2 : char*                     ****
**** Entraîne: Si pcStr1 contient cToken : ****
****      pcStr1 se fini à l'indice de     ****
****    cToken                             ****
****      pcStr2 contient la suite de la   ****
****    chaine de cararctères              ****
****    Sinon :                            ****
****      pcStr1 inchangée                 ****
****      pcStr2 = "\0"                    ****
**** Sortie: Rien                          ****
**********************************************/
void CParser::PARSeparateString(char cToken, char* pcStr1, char* pcStr2)
{
	bool bCopie = false;
	unsigned int uiBoucleDst = 0;
	int uiIndiceFinStr = -1;
	
	for (unsigned int uiBoucleSrc = 0; pcStr1[uiBoucleSrc] != '\0'; uiBoucleSrc++)
	{
		if (bCopie == true)
		{
			pcStr2[uiBoucleDst] = pcStr1[uiBoucleSrc];
			uiBoucleDst++;
		}
		else if (pcStr1[uiBoucleSrc] == cToken)
		{
			bCopie = true;
			uiIndiceFinStr = uiBoucleSrc;
		}
	}
	
	if (uiIndiceFinStr != -1)
	{
		pcStr1[uiIndiceFinStr] = '\0';
	}
	pcStr2[uiBoucleDst] = '\0';
}

/************************************************
**** Nom: PARIsStringEqual                   ****
*************************************************
****                                         ****
*************************************************
**** Précondition: pccStr1 & pccStr2 chaines ****
****    de caractère valide (terminée par un ****
****    '\0')                                ****
**** Entrée: pccStr1 : const char *          ****
****    pccStr2 : const char *               ****
**** Entraîne: Rien                          ****
**** Sortie: Vrai si la chaine de caractère  ****
****    pointée par pccStr1 = la chaine de   ****
****    caractère pointée par pccStr2        ****
****    Faux sinon                           ****
************************************************/
bool CParser::PARIsStringEqual(const char * pccStr1, const char * pccStr2)
{
	unsigned int uiBoucleStr = 0;
	bool bResultat = true;
	
	while (bResultat == true && pccStr1[uiBoucleStr] != '\0' && pccStr2[uiBoucleStr] != '\0')
	{
		if (pccStr1[uiBoucleStr] != pccStr2[uiBoucleStr])
		{
			bResultat = false;
		}
		
		uiBoucleStr++;
	}
	
	if (pccStr1[uiBoucleStr] != pccStr2[uiBoucleStr])
	{
		bResultat = false;
	}
	return bResultat;
}

/************************************************
**** Nom: PARIsStringANumericalValue         ****
*************************************************
****                                         ****
*************************************************
**** Précondition: pcStr chaine de caractère ****
****    valide (terminée par un '\0')        ****
**** Entrée: pcStr : const char *            ****
**** Entraîne: Rien                          ****
**** Sortie: Vrai si pcStr pointe vers une   ****
****    chaine de caractère composée de      ****
****    chiffre ou de point                  ****
****    Faux sinon                           ****
************************************************/
bool CParser::PARIsStringANumericalValue(const char * pcStr)
{
	bool bIsNumericalValue = true;
	
	for (unsigned int uiBoucleStr = 0; pcStr[uiBoucleStr] != '\0' && bIsNumericalValue; uiBoucleStr++)
	{
		if ((pcStr[uiBoucleStr] < '0' || pcStr[uiBoucleStr] > '9') && pcStr[uiBoucleStr] != '.' && pcStr[uiBoucleStr] != '-')
		{
			bIsNumericalValue = false;
		}
	}
	
	return bIsNumericalValue;
}