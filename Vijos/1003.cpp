#include <cstring>
#include <iostream>
#define MAXN 100
#define ZERO 10
using namespace std;

char sta[MAXN];
int n, p1, p2;
long long f[ZERO << 2], nf[ZERO << 2], num[MAXN];
string a;

inline long long Pow(long long a, long long b)
{
	long long res = 1;
	for (int i = 0; i < b; i++) res *= a;
	return res;
}

inline int cmp(char a, char b)
{
	int va, vb;
	if (a == '(') return -1;
	if (a == '+' || a == '-') va = 0;
	else if (a == '*') va = 1;
	else va = 2;
	if (b == '+' || b == '-') vb = 0;
	else if (b == '*') vb = 1;
	else vb = 2;
	return va - vb;
}

inline void Calculate(int p, char opt)
{
	if (opt == '+') num[p - 1] = num[p - 1] + num[p];
	if (opt == '-') num[p - 1] = num[p - 1] - num[p];
	if (opt == '*') num[p - 1] = num[p - 1] * num[p];
	if (opt == '^') num[p - 1] = Pow(num[p - 1], num[p]);
	return ;
}

inline long long Solve(int x)
{
	int n = a.length(), m = 0;
	p1 = p2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == ' ') continue;
		if (a[i] == 'a') num[++p1] = x;
		else if (a[i] >= '0' && a[i] <= '9') m = m * 10 + a[i] - '0';
		else
		{
			if (m)
			{
				num[++p1] = m;
				m = 0;
			}
			if (a[i] == '(') sta[++p2] = a[i];
			else if (a[i] == ')') while (p2 && sta[p2--] != '(') Calculate(p1--, sta[p2 + 1]);
			else
			{
				while (p2 && cmp(sta[p2], a[i]) >= 0) Calculate(p1--, sta[p2--]);
				sta[++p2] = a[i];
			}
		}
	}
	if (m) num[++p1] = m;
	while (p2) Calculate(p1--, sta[p2--]);
	return num[1];
}

inline void GetF(long long f[])
{
	for (int i = -ZERO; i <= ZERO; i++) f[i + ZERO] = Solve(i);
	return ;
}

inline bool Compare()
{
	for (int i = 0; i < ZERO << 1; i++) if (f[i] != nf[i]) return false;
	return true;
}

int main()
{
	getline(cin, a);
	GetF(f);
	cin >> n;
	getline(cin, a);
	for (int i = 0; i < n; i++)
	{
		getline(cin, a);
		GetF(nf);
		if (Compare()) cout << char(i + 'A');
	}
	cout << endl;
	return 0;
}
