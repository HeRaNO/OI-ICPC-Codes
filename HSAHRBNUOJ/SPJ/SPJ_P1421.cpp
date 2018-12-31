//By peter_819
#include <bits/stdc++.h>
#define MAXN 1001
using namespace std;
int n, m;
int a[MAXN], b[MAXN];
int mat[MAXN][MAXN];
bool used[MAXN];
int sum[MAXN];
int main(int argc, char const *argv[])
{
	ifstream fin(argv[1]), fout(argv[2]), fuser(argv[3]);
	fin >> n >> m;
	for (int i = 1; i <= n; i++) fin >> a[i];
	for (int i = 1; i <= m; i++) fin >> b[i];
	int t, tt;
	fout >> t;
	fuser >> tt;
	if (t != tt)
	{
		printf("1WA\n");
		return 1;
	}
	if (t == 0)
		return 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= a[i]; j++)
			fuser >> mat[i][j];
	for (int i = 1; i <= n; i++)
	{
		memset(used, 0, sizeof used);
		for (int j = 1; j <= a[i]; j++)
		{
			if (used[mat[i][j]])
			{
				printf("2WA\n");
				return 1;
			}
			used[mat[i][j]] = 1;
			sum[mat[i][j]]++;
		}
	}
	for (int i = 1; i <= m; i++)
		if (sum[i] > b[i])
		{
			printf("3WA\n");
			return 1;
		}
	printf("AC\n");
	return 0;
}