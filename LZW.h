//�����, �� �������� �������� �������� ����-�������
#pragma once 
class LZW: public Compress, public Decompress
{
public:
	LZW(); 
	void Update();
private:
	bool flag=true;
};

