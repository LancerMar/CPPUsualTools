#include "stdafx.h"
#include "tools.h"

char * TransHLAndByte(unsigned char * testByte,int byteLen)
{
	char result[]="";

	char tmptrans[]="";
	for (int i = 0; i < byteLen; i++)
	{
		//取低四位，高四位是符号
		tmptrans[2 * i] = (testByte[i] & 0x0f);
		tmptrans[2 * i + 1] = (testByte[i] & 0xf0) >> 4;
	}
	for (int i = 0; i < byteLen*2-1; i++)
	{
		if (tmptrans[i + 1] >= 0x00 && tmptrans[i + 1] <= 0x09)
		{
			result[i] = tmptrans[i + 1] + '0';
		}
	}

	return result;
}