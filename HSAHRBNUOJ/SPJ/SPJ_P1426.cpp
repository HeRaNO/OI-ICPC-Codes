#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

int n, m, um, pos, len;
bool g[MAXN][MAXN];
int city[MAXN];
string a, b;
map <string, int> mp;
map <string, int> :: iterator it1, it2;

int main(int argc, char const *argv[])
{
	ifstream fin(argv[1]), fout(argv[2]), fuser(argv[3]);
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		fin >> a;
		mp.insert(make_pair(a, i));
	}
	for (int i = 1; i <= m; i++)
	{
		fin >> a >> b;
		it1 = mp.find(a);
		it2 = mp.find(b);
		g[it1->second][it2->second] = g[it2->second][it1->second] = true;
	}
	fout >> a;
	fuser >> b;
	if (a != b)
	{
		puts("Solution Wrong!");
		return 1;
	}
	if (a == "No")
	{
		fuser >> b;
		if (b != "Solution!")
		{
			puts("Solution Wrong!");
			return 1;
		}
	}
	len = b.size();
	for (int i = 0; i < len; i++) um = (um << 3) + (um << 1) + b[i] - '0';
	for (int i = 1; i <= um + 1; i++)
	{
		fuser >> a;
		it1 = mp.find(a);
		if (it1 == mp.end())
		{
			puts("Don't have this city!");
			cout << a << endl;
			return 1;
		}
		city[i] = it1->second;
	}
	for (int i = 1; i <= um; i++)
		if (!g[city[i]][city[i + 1]])
		{
			puts("There is no airline between the two city!");
			return 1;
		}
	for (int i = 1; i <= um; i++)
		if (city[i + 1] < city[i])
		{
			pos = i;
			break;
		}
	for (int i = pos + 1; i <= um + 1; i++)
		if (city[i] > city[pos])
		{
			puts("Back to east city!");
			return 1;
		}
	puts("AC!");
	return 0;
}