#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

string s = "\0";
int i, n, p;
int ans = 0;
char ed;

void dfs(int dep)
{
	if (dep == n + 1)
	{
		ans++;
		return ;
	}
	char ch;
	int j;
	for (ch = 'a'; ch <= ed; ch++)
	{
		s += ch;
		j = 1;
		while (j <= dep / 2)
		{
			string s1 = s.substr(s.size() - j, j);
			string s2 = s.substr(s.size() - 2 * j, j);
			if (s1 != s2) j++;
			else break;
		}
		if (j > dep / 2) dfs(dep + 1);
		s.erase(s.size() - 1, 1);
	}
}

int main()
{
	//freopen("data.in","r",stdin);freopen("data.out","w",stdout);
	scanf("%d %d", &n, &p);
	ed = (char)('a' + p - 1);
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
