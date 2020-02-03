#include <cstring>
#include <iostream>
#define MAXN 110
using namespace std;

int n, T = 1, w, pos;
string pass[MAXN * MAXN], word[MAXN];
string S;
char ch;

inline char uppercase(char a)
{
	if (a >= 'a' && a <= 'z') a -= 32;
	return a;
}

int check(string x, string y)
{
	int t = 0;
	for (int i = 0; i < x.length(); i++) if (uppercase(x[i]) != uppercase(y[i])) t++;
	return t;
}

int main()
{
	cin >> n;
	getchar();
	while (true)
	{
		ch = getchar();
		if (ch == ' ')
		{
			T++;
			continue;
		}
		if (ch == '!') break;
		pass[T] += ch;
	}
	getchar();
	for (int i = 1; i <= n; i++) cin >> word[i];
	pass[1][0] += 32;
	for (int i = 1; i <= T; i++)
		for (int j = 1; j <= n; j++)
		{
			int t = check(pass[i], word[j]);
			if (t <= 1)
			{
				pass[i] = word[j];
				if (t == 1) w++;
				break;
			}
		}
	pass[1][0] -= 32;
	cout << w << endl;
	for (int i = 1; i < T; i++) cout << pass[i] << " ";
	cout << pass[T] << '!' << endl;
	return 0;
}
