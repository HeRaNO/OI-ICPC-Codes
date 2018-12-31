//Code By HeRaNO
#include<stdio.h>
#include<string.h>
char j1[500];
char j2[500];
int main()
{
	float a, bi, chang, sum = 0;
	int i;
	scanf("%f", &a);
	scanf("%s", j1);
	chang = strlen(j1);
	scanf("%s", j2);
	for (i = 0; i <= chang - 1; i++)
		if (j1[i] == j2[i]) sum++;
	bi = sum / chang;
	if (bi >= a) printf("yes");
	else printf("no");
}
