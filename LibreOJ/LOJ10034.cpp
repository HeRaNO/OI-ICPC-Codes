#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 30010
using namespace std;

const long long S1 = 131LL;
const long long M1 = 275593LL;
const long long S2 = 133LL;
const long long M2 = 275591LL;

struct Hashlink
{
	long long y;
	int nxt;
};

Hashlink e[MAXN];
int n, i, l, head[M1], cnt;
long long x, y;
string s;

void add(long long x, long long y)
{
	e[cnt] = (Hashlink)
	{
		y, head[x]
	};
	head[x] = cnt++;
	return ;
}

bool query(long long x, long long y)
{
	for (int i = head[x]; ~i; i = e[i].nxt)
		if (e[i].y == y) return true;
	return false;
}

int main()
{
	memset(head, -1, sizeof head);
	cin >> n;
	getline(cin, s);
	while (n--)
	{
		getline(cin, s);
		l = s.length();
		x = 0LL;
		y = 0LL;
		for (s[0] == 'a' ? i = 4 : i = 5; i < l; i++) x = (x * S1 + s[i]) % M1, y = (y * S2 + s[i]) % M2;
		if (s[0] == 'a') add(x, y);
		else
		{
			if (query(x, y)) puts("yes");
			else puts("no");
		}
	}
	return 0;
}