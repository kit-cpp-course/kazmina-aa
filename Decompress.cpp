#include "stdafx.h"
 

void Decompress::ProcessDecompress(char *InFileName, char *OutFileName)
{ 
	if ((InF = fopen(InFileName, "rb")) == NULL)
	{
		printf("ERROR\n");
		return;
	}
	if ((OutF = fopen(OutFileName, "wb")) == NULL)
	{
		printf("ERROR\n");
		return;
	}
	Decode();  
	fclose(InF);
	fclose(OutF);
}

void Decompress::Decode()
{
	char i;
	long long size = 10000;
	CODE *Dict = (CODE *)malloc(size * sizeof(CODE));
	int num = 0, DictLen = 0;
	Dict[0].Ch = 'ÿ';
	Dict[0].Prv = 0;
	while (fscanf(InF, "%d@", &num) != EOF)
	{
		i = fgetc(InF);
		if (DictLen + 1 > size)
		{
			size *= 2;
			Dict = (CODE *)realloc(Dict, size * sizeof(CODE));
		}
		Put(Dict, i, num, &DictLen);
		Write(Dict, DictLen);
	}
	printf("Decompress completed\n");
	free(Dict);
}

void Decompress::Put(CODE *Dict, char ch, int num, int *Len)
{
	(*Len)++;
	Dict[(*Len)].Ch = ch;
	Dict[(*Len)].Prv = num;
}

void Decompress::Write(CODE *Dict, int DictLen)
{
	int num = DictLen, i = 0, Len = -1;
	char NewString[10000];
	while (num != 0)
	{
		NewString[i] = Dict[num].Ch;
		num = Dict[num].Prv;
		Len++;
		i++;
	}
	for (i = Len; i >= 0; i--)
		fputc(NewString[i], OutF);
} 