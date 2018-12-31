//Code By HeRaNO
#include<stdio.h>
#include<string.h>
int main()
{
	char n[255];
	int i;
	gets(n);
	for (i = 0; i < strlen(n); i++)
	{
		if (n[i] == 'A') n[i] = 'T';
		else if (n[i] == 'G') n[i] = 'C';
		else if (n[i] == 'C') n[i] = 'G';
		else if (n[i] == 'T') n[i] = 'A';
	}
	puts(n);
	return 0;
}
