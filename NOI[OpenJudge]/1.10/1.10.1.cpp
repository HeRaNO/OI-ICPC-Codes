//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	int n, k, j, i;
	cin >> n >> k;
	long long xuehao[n], t;
	double fen[n], q;
	for (i = 1; i <= n; i++) cin >> xuehao[i] >> fen[i];
	for (j = 1; j <= n - 1; j++)
		for (i = 1; i <= n - j; i++)
		{
			if (fen[i] < fen[i + 1])
			{
				q = fen[i];
				fen[i] = fen[i + 1];
				fen[i + 1] = q;
				t = xuehao[i];
				xuehao[i] = xuehao[i + 1];
				xuehao[i + 1] = t;
			}
		}
	cout << xuehao[k] << " " << fen[k];
	return 0;
}
