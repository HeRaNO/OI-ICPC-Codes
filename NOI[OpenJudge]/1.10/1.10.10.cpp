//Code By HeRaNO
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXN 120
using namespace std;

string a[MAXN];
int cnt;

bool cmp(string a, string b)
{
	return a < b;
}

int main()
{
	while (cin >> a[cnt]) cnt++;
	sort(a, a + cnt, cmp);
	for (int i = 0; i < cnt; i++)
	{
		if (a[i] == a[i + 1]) continue;
		cout << a[i] << endl;
	}
	return 0;
}
