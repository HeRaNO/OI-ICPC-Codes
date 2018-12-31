//Code By HeRaNO
#include <cstring>
#include <iostream>
using namespace std;

string s1, s2;
int len1, len2;
int ans, best;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	cin >> s1 >> s2;
	len1 = s1.length();
	len2 = s2.length();
	s1 += s1;
	s2 += s2;
	for (int i = 0; i < len1; i++)
		for (int j = 0; j < len2; j++)
		{
			while (s1[i + best] == s2[j + best] && best <= len1 && best <= len2)
				best++;
			ans = mymax(ans, best);
			best = 0;
		}
	ans = mymin(ans, mymin(len1, len2));
	cout << ans;
	return 0;
}
