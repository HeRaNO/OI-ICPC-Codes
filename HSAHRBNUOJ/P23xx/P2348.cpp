#include <map>
#include <cstdio>
#include <iostream>
#define MAXN 35
using namespace std;

map <string, int> hash_table;
string name1, name2;
int n, m, cnt, cas;
double q;
bool flag;
double dis[MAXN][MAXN];

double mymax(double a, double b)
{
	return a > b ? a : b;
}

int main()
{
	//freopen("arbi.in","r",stdin);freopen("arbi.out","w",stdout);
	while (cin >> n)
	{
		cas++;
		printf("Case %d: ", cas);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = 0;
		for (int i = 1; i <= n; i++) dis[i][i] = 1;
		flag = false;
		for (int i = 1; i <= n; i++)
		{
			cin >> name1;
			hash_table[name1] = i;
		}
		cin >> m;
		for (int i = 1; i <= m; i++)
		{
			cin >> name1 >> q >> name2;
			dis[hash_table[name1]][hash_table[name2]] = q;
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dis[i][j] = mymax(dis[i][j], dis[i][k] * dis[k][j]);
		for (int i = 1; !flag && i <= n; i++)
			if (dis[i][i] > 1)
				flag = true;
		if (!flag) puts("No");
		else puts("Yes");
		//scanf("\n");
	}
	return 0;
}