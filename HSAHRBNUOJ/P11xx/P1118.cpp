#include <iostream>
using namespace std;
int main()
{
	int n, maxpos, minpos, i;
	cin >> n;
	long shu[101] = {0}, max, min;
	for (i = 1; i <= n; i++)
		cin >> shu[i];
	max = shu[1];
	min = shu[1];
	for (i = 2; i <= n; i++)
	{
		if (shu[i] > max) max = shu[i];
		if (shu[i] < min) min = shu[i];
	}
	for (i = 1; i <= n; i++)
		if (shu[i] == max)
		{
			maxpos = i;
			break;
		}
	for (i = 1; i <= n; i++)
		if (shu[i] == min)
		{
			minpos = i;
			break;
		}
	shu[maxpos] = min;
	shu[minpos] = max;
	for (i = 1; i < n; i++)
		cout << shu[i] << " ";
	cout << shu[n] << endl;
	return 0;
}
