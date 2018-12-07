#include "stdafx.h"
#include "tools.h"
#include <string>
#include <cstring>

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

//16进制ip转化为10进制字符型IP
void ipTstrIP(unsigned int ip, char *ipchar)
{
	char ip_temp[64];
	std::string str = "";
	int temp;
	int ipSize = sizeof(ip);

	for (int i = 0; i < ipSize; i++)
	{
		temp = (ip >> 8 * (ipSize - 1 - i)) & 0xFF;
		str += std::to_string(temp) + ".";
	}
	str.erase(str.end() - 1);
	//cout << str << endl;

	//cout << str.length() << endl;

	int i = 0;
	for (i = 0; i < str.length(); i++)
	{
		*(ipchar + i) = str[i];
	}
	*(ipchar + i) = '\0';
	//strcpy(ipchar, ip_temp);

}