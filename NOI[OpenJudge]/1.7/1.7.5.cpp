//Code By HeRaNO
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[110], b[110];
	int m, i;
	gets(a);
	m = strlen(a);
	for (i = 0; i < m - 1; i++)
		b[i] = (int)a[i + 1] + (int)a[i];
	b[m - 1] = (int)a[0] + (int)a[m - 1];
	for (i = 0; i < m; i++)
		printf("%c", b[i]);
	return 0;
}
