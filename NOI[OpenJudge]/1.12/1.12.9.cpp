//Code By HeRaNO
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int pic[110][110];

void moveA(int m, int n)
{
	int a[110][110];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			a[j][m + 1 - i] = pic[i][j];
	swap(m, n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			pic[i][j] = a[i][j];
}

void moveB(int m, int n)
{
	int a[110][110];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			a[n + 1 - j][i] = pic[i][j];
	swap(m, n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			pic[i][j] = a[i][j];
}

void moveC(int m, int n)
{
	int a[110][110];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			a[i][n + 1 - j] = pic[i][j];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			pic[i][j] = a[i][j];
}

void moveD(int m, int n)
{
	int a[110][110];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			a[m + 1 - i][j] = pic[i][j];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			pic[i][j] = a[i][j];
}

int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> pic[i][j];
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
			int t;
		case 'A' :
			moveA(m, n);
			swap(m, n);
			break;
		case 'B' :
			moveB(m, n);
			swap(m, n);
			break;
		case 'C' :
			moveC(m, n);
			break;
		case 'D' :
			moveD(m, n);
			break;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << pic[i][j] << " ";
		cout << endl;
	}
	return 0;
}
