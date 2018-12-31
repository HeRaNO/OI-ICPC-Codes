#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 210
using namespace std;

string afraid[MAXN], dream;
int v[MAXN];
int n, m, pos;
long long ans;

int main()
{
	//freopen("dream.in","r",stdin);freopen("dream.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> afraid[i];
	for (int i = 1; i <= m; i++) cin >> v[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> dream;
		for (int j = 1; j <= m; j++)
		{
			pos = 0;
			while (pos < dream.length())
			{
				pos = dream.find(afraid[j], pos);
				pos++;
				if (!pos) break;
				ans += pos * v[j];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
