#include "stdafx.h"

LZW::LZW(): flag(true), LZW::Compress::Compress(), LZW::Decompress::Decompress()
{

}

void LZW::Update()
{
	while (flag)
	{
		printf("LZW\n");
		printf("0 - Exit\n");
		printf("1 - Compress\n");
		printf("2 - Decompress\n");
		switch (_getch())
		{
		case'0':
			flag = false;
			break;
		case'1':
		{
			char In[100], Out[100];
			printf("\nInput infile name: ");
			scanf("%s", &In);
			printf("Input outfile name: ");
			scanf("%s", &Out);  
			LZW::Compress::ProcessCompress(In, Out);
			break;
		}
		case'2':
		{
			char In[100], Out[100];
			printf("\nInput infile name: ");
			scanf("%s", &In);
			printf("Input outfile name: ");
			scanf("%s", &Out);  
			LZW::Decompress::ProcessDecompress(In, Out);
			break;
		}
		default:
			printf("\nWrong key pressed\n\n");
		}
	}
}
 