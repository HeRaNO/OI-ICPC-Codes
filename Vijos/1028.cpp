#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#define MAXN 2001
using namespace std;

int n, i, j;
int ans;
int si;
string word[MAXN];
stack <string> s;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

bool cmp(string a, string b)
{
	if (a.size() <= b.size()) return false;
	for (int i = 0; i < b.size(); i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		cin >> word[i];
	for (i = 1; i <= n; i++)
	{
		ans = mymax(ans, s.size());
		if (s.empty())
		{
			s.push(word[i]);
			continue;
		}
		if (cmp(word[i], s.top()))
		{
			s.push(word[i]);
			continue;
		}
		else
		{
			while (!s.empty())
			{
				s.pop();
				if (s.empty() || cmp(word[i], s.top()))
				{
					s.push(word[i]);
					break;
				}
			}
		}
		ans = mymax(ans, s.size());
	}
	ans = mymax(ans, s.size());
	printf("%d\n", ans);
	return 0;
}
