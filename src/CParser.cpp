#include <header/CParser.h>

void CParser::PARSeparateString(char cToken, const char* src, char* dst)
{
	bool bCopie = false;
	unsigned int uiBoucleDst = 0;
	
	for (unsigned int uiBoucleSrc = 0; src[uiBoucleSrc] != '\0'; uiBoucleSrc++)
	{
		if (bCopie == true)
		{
			dst[uiBoucleDst] = src[uiBoucleSrc];
			uiBoucleDst++;
		}
		else if (src[uiBoucleSrc] == cToken)
		{
			bCopie = true;
		}
	}
	
	dst[uiBoucleDst] = '\0';
}

bool CParser::PARStringCompare(const char * str1, const char * str2)
{
	unsigned int uiBoucleStr1 = 0;
	unsigned int uiBoucleStr2 = 0;
	bool bResultat = true;
	
	while (bResultat == true && str1[uiBoucleStr1] != '\0' && str2[uiBoucleStr2] != '\0')
	{
		if (str1[uiBoucleStr1] != str2[uiBoucleStr2])
		{
			bResultat = false;
		}
		
		uiBoucleStr1++;
		uiBoucleStr2++;
	}
	
	if (str1[uiBoucleStr1] != str2[uiBoucleStr2])
	{
		bResultat = false;
	}
	return bResultat;
}