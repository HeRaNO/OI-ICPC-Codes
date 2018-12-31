#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 10010
using namespace std;

int n, m;
string name, pt;
string join;
map <string, string> name_table;
map <string, int> pro_table;
string ptt[MAXN];
vector <string> v[MAXN];
string project[MAXN];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> project[i];
		pro_table[project[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> pt >> name;
		name_table[pt] = name;
		ptt[i] = pt;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> join;
		for (int j = 0; j < m; j++)
			if (join[j] == '1')
				v[j + 1].push_back(ptt[i]);
	}
	for (int i = 1; i <= m; i++)
		sort(v[i].begin(), v[i].end());
	for (int i = 1; i <= m; i++)
	{
		cout << project[i] << endl;
		for (int j = 0; j < v[i].size(); j++) cout << v[i][j] << " " << name_table[v[i][j]] << endl;
		cout << endl;
	}
	return 0;
}
