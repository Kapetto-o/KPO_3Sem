#include <iostream>
#pragma comment(lib, "..\\Debug\\SE_asm01a.lib")

extern "C"
{
	int __stdcall getmax(int*, int);
	int __stdcall getmin(int*, int);
}

int main()
{
	int array[10] = { -1, 2, -3, 4, -5, 6, -7, 8, -9, 10 };
	int max = getmax(array, sizeof(array) / sizeof(int));
	int min = getmin(array, sizeof(array) / sizeof(int));
	std::cout << "getmax + getmin = " << max + min << std::endl;
}