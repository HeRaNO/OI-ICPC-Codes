#include <iostream>
using namespace std;
int l[10010];
int main()
{
	int n, m;
	cin >> n >> m;
	int a, b;
	int sum = 0;
	int i, j;
	for (i = 1; i <= m; i++)
	{
		cin >> a >> b;
		for (j = a; j <= b; j++) l[j]++;
	}
	for (i = 0; i <= n; i++)
		if (l[i] == 0) sum++;
	cout << sum;
	return 0;
}
