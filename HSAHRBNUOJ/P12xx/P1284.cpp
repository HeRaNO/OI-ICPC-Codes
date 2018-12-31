#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#define mymaxN 10001
using namespace std;
int n, ans;
stack <string> s;
string word[mymaxN];
bool cmp(string a, string b)
{
	int i;
	for (i = 0; i < b.size(); i++)
		if (a[i] != b[i])
			return false;
	return true;
}
int mymax(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int main()
{
	//freopen("link.in","r",stdin);
	//freopen("link.out","w",stdout);
	int i;
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
				if (cmp(word[i], s.top()) || s.empty())
				{
					s.push(word[i]);
					break;
				}
			}
		}
		ans = mymax(ans, s.size());
	}
	ans = mymax(ans, s.size());
	printf("%d", ans);
	return 0;
}
