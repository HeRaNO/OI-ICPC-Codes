//Code By HeRaNO
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int key[100];
	char k[100], mw[1000], ans[1000];
	int i, lk, lmw;
	cin >> k >> mw;
	lk = strlen(k);
	lmw = strlen(mw);
	for (i = 0; i < lk; i++)
	{
		if (k[i] >= 'a')key[i] = k[i] - 'a';
		else key[i] = k[i] - 'A';
	}
	i = 0;
	while (i < lmw)
	{
		ans[i] = mw[i] - key[i % lk];
		if ((ans[i] < 'A') || (ans[i] < 'a' && mw[i] >= 'a')) ans[i] = ans[i] + 26;
		cout << ans[i];
		i++;
	}
	return 0;
}
