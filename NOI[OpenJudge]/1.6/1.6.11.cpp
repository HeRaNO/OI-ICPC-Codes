//Code By HeRaNO
#include <cstdio>
#define MAXL 210
using namespace std;

char c;
int ta[MAXL], tb[MAXL];
int a[MAXL], b[MAXL];
int lena, lenb, tlena, tlenb;
int ans[MAXL], anslen;
bool print = false;

int main()
{
	while (true)
	{
		c = getchar();
		if (c >= '0' && c <= '9') ta[++lena] = c - '0';
		else break;
	}
	tlena = lena;
	while (true)
	{
		c = getchar();
		if (c >= '0' && c <= '9') tb[++lenb] = c - '0';
		else break;
	}
	tlenb = lenb;
	for (int i = 1; i <= lena; i++) a[i] = ta[tlena--];
	for (int i = 1; i <= lenb; i++) b[i] = tb[tlenb--];
	anslen = lena > lenb ? lena : lenb;
	int jin = 0;
	for (int i = 1; i <= anslen; i++)
	{
		ans[i] += a[i] - b[i];
		if (ans[i] < 0)
		{
			a[i + 1]--;
			ans[i] += 10;
		}
	}
	if (jin) ans[++anslen] = jin;
	int i;
	for (i = anslen; i; i--)
		if (ans[i]) break;
	for (int j = i; j; j--)
	{
		printf("%d", ans[j]);
		print = true;
	}
	if (!print) printf("0");
	return 0;
}
