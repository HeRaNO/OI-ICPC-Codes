#include <iostream>
using namespace std;
int main()
{
	char ch[26], l, r;
	int w, i, k, j;
	cin >> i >> j >> w;
	l = i + 'a' - 1;
	r = j + 'a' - 1;
	cin >> ch;
	for (i = 1; i <= 5; i++)
	{
		j = w - 1;
		while (j >= 0 && ch[j] == r + j + 1 - w) j--;
		if (j == -1) break;
		ch[j]++;
		for (k = j + 1; k <= w - 1; k++)
			ch[k] = ch[k - 1] + 1;
		cout << ch << endl;
	}
	return 0;
}