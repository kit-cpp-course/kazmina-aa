#include "stdafx.h"  

void Compress::ProcessCompress(char *InFileName, char *OutFileName)
{ 
	if ((InF = fopen(InFileName, "rb")) == NULL)
	{
		printf("ERROR reading fail\n");
		return;
	}
	if ((OutF = fopen(OutFileName, "wb")) == NULL)
	{
		printf("ERROR\n");
		return;
	}
	Code();
	fclose(InF);
	fclose(OutF);
}

void Compress::Code()
{
	char i;
	int size = 10000;
	CODE *Dict = (CODE *)malloc(size * sizeof(CODE));
	int num = 0, DictLen = 0, total = 0, unpack = 0;
	double ratio;
	Dict[0].Ch = 'ÿ';
	Dict[0].Prv = 0;
	while ((i = fgetc(InF)) != EOF)
	{
		unpack += 8;
		if (!Find(Dict, i, &num, DictLen))
		{
			if (DictLen > size - 1)
			{
				size *= 2;
				Dict = (CODE *)realloc(Dict, size * sizeof(CODE));
			}
			Put(Dict, i, num, &DictLen);
			fprintf(OutF, "%d@", num);
			fputc(i, OutF);
			if (num == 0)
				total += 24;
			else
				total += 8 * ((int)log10(num) + 3);
			num = 0;
		}
	}
	if (num != 0)
	{
		fprintf(OutF, "%d@", Dict[num].Prv);
		fputc(Dict[num].Ch, OutF);
		total += 8 * ((int)log10(Dict[num].Prv) + 3);
	}
	ratio = (double)unpack / total;
	printf("Compress completed\n"); 
	free(Dict);

}

bool Compress::Find(CODE *Dict, char ch, int *num, int Len)
{
	int i;
	for (i = *num; i <= Len; i++)
		if ((ch == Dict[i].Ch) && (*num == Dict[i].Prv))
		{
			(*num) = i;
			return true;
		}
	return false;
}

void Compress::Put(CODE *Dict, char ch, int num, int *Len)
{
	(*Len)++;
	Dict[(*Len)].Ch = ch;
	Dict[(*Len)].Prv = num;
}
 