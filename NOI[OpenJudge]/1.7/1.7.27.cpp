//Code By HeRaNO
#include <stack>
#include <cstdio>
#include <cstring>
#define MAXN 510
using namespace std;
stack <char> s;
char c[MAXN];
int len;
int main()
{
	gets(c);
	len = strlen(c);
	for (int i = 0; i < len; i++)
	{
		if (c[i] != ' ') s.push(c[i]);
		else
		{
			while (!s.empty())
			{
				printf("%c", s.top());
				s.pop();
			}
			printf(" ");
		}
	}
	while (!s.empty())
	{
		printf("%c", s.top());
		s.pop();
	}
	return 0;
}
