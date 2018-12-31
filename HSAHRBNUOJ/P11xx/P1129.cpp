#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char b[510];
	int c;
	gets(b);
	c = strlen(b);
	for (int i = c - 2; i >= 1; i--)
		cout << b[i] << " ";
	cout << b[0] << endl;
	return 0;
}
