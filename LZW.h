//класс, по которому действет алгоритм Зива-Лемпеля
#pragma once 
class LZW: public Compress, public Decompress
{
public:
	LZW(); 
	void Update();
private:
	bool flag=true;
};

