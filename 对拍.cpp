#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main()
{
	system("g++ data.cpp -o data -O2");
	system("g++ std.cpp -o std -O2");
	system("g++ my.cpp -o test -O2");
	clock_t st, ed;
	for (int i = 1; ; i++)
	{
		printf("%d\n", i);
		//Sleep(1000);
		system("data > in");
		system("std < in > sout");
		st = clock();
		system("test < in > tout");
		ed = clock();
		printf("Time used:%lfs\n", (double)(ed - st) / CLOCKS_PER_SEC);
		int k = system("fc sout tout");
		if (k) break;
		printf("AC\n");
	}
	return 0;
}