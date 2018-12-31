#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main()
{
	system("g++ data.cpp -o data -O2");
	system("g++ std.cpp -o std -O2");
	system("g++ my.cpp -o test");
	clock_t st, ed;
	for (int i = 1; i <= 10; i++)
	{
		printf("%d\n", i);
		//Sleep(1000);
		system("data");
		system("std");
		st = clock();
		system("test");
		ed = clock();
		printf("Time used:%lfs\n", (double)(ed - st) / CLOCKS_PER_SEC);
		int k = system("fc std.out test.out");
		if (k) break;
		printf("AC\n");
	}
	return 0;
}