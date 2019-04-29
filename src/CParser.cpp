#include <header/CParser.h>

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

bool CParser::PARIsStringEqual(const char * str1, const char * str2)
{
	unsigned int uiBoucleStr = 0;
	bool bResultat = true;
	
	while (bResultat == true && str1[uiBoucleStr] != '\0' && str2[uiBoucleStr] != '\0')
	{
		if (str1[uiBoucleStr] != str2[uiBoucleStr])
		{
			bResultat = false;
		}
		
		uiBoucleStr++;
	}
	
	if (str1[uiBoucleStr] != str2[uiBoucleStr])
	{
		bResultat = false;
	}
	return bResultat;
}

bool CParser::PARIsStringANumericalValue(const char * pcStr)
{
	bool bIsNumericalValue = true;
	
	for (unsigned int uiBoucleStr = 0; pcStr[uiBoucleStr] != '\0' && bIsNumericalValue; uiBoucleStr++)
	{
		if (pcStr[uiBoucleStr] <= '0' || pcStr[uiBoucleStr] >= '9' || pcStr[uiBoucleStr] != '.')
		{
			bIsNumericalValue = false;
		}
	}
	
	return bIsNumericalValue;
}