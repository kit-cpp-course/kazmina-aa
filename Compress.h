#pragma once
//�����, ������� �������� ���� � ��������� ��� ������ 
class Compress
{
public:
	void ProcessCompress(char *InFileName,char *OutFileName); 
	void Code();
	void Put(CODE *Dict, char ch, int num, int *Len);
	bool Find(CODE *Dict, char ch, int *num, int Len);
private:
	FILE *InF, *OutF;
};
 