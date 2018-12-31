#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n;
char l;
string p;
set <string> s;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p;
		if (i != 1 && p[0] != l)
		{
			puts("No");
			return 0;
		}
		if (s.count(p))
		{
			puts("No");
			return 0;
		}
		s.insert(p);
		l = p[p.length() - 1];
	}
	puts("Yes");
	return 0;
}