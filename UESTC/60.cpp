#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T,i;cin>>T;
	string s;getline(cin,s);
	while (T--)
	{
		int cnt=0;
		getline(cin,s);i=0;
		while (i<s.length())
		{
			while (!isalpha(s[i])&&i<s.length()) ++i;
			if (i<s.length()) ++cnt;
			while (isalpha(s[i])&&i<s.length()) ++i;
		}
		printf("%d\n",cnt);
	}
	return 0;
}