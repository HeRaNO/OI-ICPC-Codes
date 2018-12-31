//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXL 110
using namespace std;

char a[MAXL], b[MAXL];
int aint[MAXL], bint[MAXL];
int adec[MAXL], bdec[MAXL];
int ansint[MAXL], ansdec[MAXL];
int cntint, cntdec;
int lena, lenb;
int tmplenb;
int dotpos;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	gets(a);
	gets(b);
	lena = strlen(a);
	lenb = strlen(b);
	for (int i = 0; i < lena; i++)
		if (a[i] == '.')
		{
			cntint = mymax(cntint, i);
			cntdec = mymax(cntdec, lena - i - 1);
			dotpos = i;
			break;
		}
	for (int i = cntint - 1; ~i; i--)
		aint[cntint - i] = a[i] - '0';
	for (int i = dotpos + 1; i < lena; i++)
		adec[i - dotpos] = a[i] - '0';
	for (int i = 0; i < lenb; i++)
		if (b[i] == '.')
		{
			dotpos = i;
			tmplenb = lenb - i - 1;
			break;
		}
	for (int i = dotpos - 1; ~i; i--)
		bint[dotpos - i] = b[i] - '0';
	for (int i = dotpos + 1; i < lenb; i++)
		bdec[i - dotpos] = b[i] - '0';
	cntint = mymax(cntint, dotpos);
	cntdec = mymax(cntdec, lenb - dotpos - 1);
	for (int i = cntdec; i; i--)
	{
		ansdec[i] += adec[i] + bdec[i];
		if (ansdec[i] >= 10)
		{
			ansdec[i] %= 10;
			ansdec[i - 1]++;
		}
	}
	ansint[1] = ansdec[0];
	for (int i = 1; i <= cntint; i++)
	{
		ansint[i] += aint[i] + bint[i];
		if (ansint[i] >= 10)
		{
			ansint[i] %= 10;
			ansint[i + 1]++;
		}
	}
	for (int i = MAXL; i; i--)
		if (ansint[i])
		{
			dotpos = i;
			break;
		}
	for (int i = dotpos; i; i--)
		printf("%d", ansint[i]);
	printf(".");
	for (int i = MAXL - 1; i; i--)
		if (ansdec[i])
		{
			dotpos = i;
			break;
		}
	for (int i = 1; i <= dotpos; i++)
		printf("%d", ansdec[i]);
	printf("\n");
	return 0;
}
