//Code By HeRaNO
#include <cstdio>
#include <cstring>
using namespace std;
char q[1000];
int main()
{
	gets(q);
	int len = strlen(q);
	for (int i = 0; i < len; i++)
	{
		if ((q[i] >= 'A' && q[i] < 'Z') || (q[i] >= 'a' && q[i] < 'z'))
			q[i]++;
		else if (q[i] == 'Z') q[i] = 'A';
		else if (q[i] == 'z') q[i] = 'a';
	}
	puts(q);
}
