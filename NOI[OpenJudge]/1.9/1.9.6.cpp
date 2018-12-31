//Code By HeRaNO
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int a[27];

bool isPrime(int q)
{
	if (q == 0 || q == 1) return false;
	int i;
	int k = (int)sqrt(q);
	for (i = 3; i <= k; i += 2)
		if (q % i == 0)
			break;
	if (i > k) return true;
	else return false;
}

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 65 && s[i] <= 90) s[i] += 32;
		a[s[i] - 'a' + 1]++;
	}
	int maxn = 0;
	for (int i = 1; i <= 26; i++)
		if (a[i] > maxn)
			maxn = a[i];
	int minn = 100;
	for (int i = 1; i <= 26; i++)
	{
		if (a[i] == 0) continue;
		if (a[i] < minn) minn = a[i];
	}
	bool q = isPrime(maxn - minn);
	if (!q)
	{
		cout << "No Answer" << endl;
		cout << 0;
		return 0;
	}
	else
	{
		cout << "Lucky Word" << endl;
		cout << maxn - minn;
		return 0;
	}
}
