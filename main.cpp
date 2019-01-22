#include "stdafx.h"

int main()
{
	LZW* AlgLZW = new LZW();
	AlgLZW->Update();
	delete AlgLZW;
	return 0;
}