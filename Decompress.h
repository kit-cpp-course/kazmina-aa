#pragma once 
 //класс, который декодирует файл в изначальный вид
class Decompress
{
public:  
	void ProcessDecompress(char *InFileName, char *OutFileName);
	void Write(CODE *Dict, int DictLen);
	void Decode();
	void Put(CODE *Dict, char ch, int num, int *Len);
private:
	FILE *InF, *OutF;
};

