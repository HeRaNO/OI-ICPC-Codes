#include <bits/stdc++.h>
using namespace std;

int n;
char a[3][1011],ans[3][1011];
vector <int> u,d,ud,nud;

int main()
{
	scanf("%s",a[1]);
	scanf("%s",a[2]);
	n=strlen(a[1]);
	for (int i=0;i<n;i++)
	{
		if (a[1][i]=='#'&&a[2][i]=='.') u.push_back(i);
		if (a[1][i]=='.'&&a[2][i]=='#') d.push_back(i);
		if (a[1][i]=='#'&&a[2][i]=='#') ud.push_back(i);
		if (a[1][i]=='.'&&a[2][i]=='.') nud.push_back(i);
	}
	if (u.size()&&!d.size()&&!ud.size())
	{
		puts("YES");
		int pt=0;
		for (int i=0;i<u.size();i++)
		{
			ans[0][pt]='#';ans[1][pt++]='.';
		}
		for (int i=0;i<nud.size();i++)
		{
			ans[0][pt]='.';ans[1][pt++]='.';
		}
		puts(ans[0]);puts(ans[1]);
		return 0;
	}
	if (d.size()&&!u.size()&&!ud.size())
	{
		puts("YES");
		int pt=0;
		for (int i=0;i<d.size();i++)
		{
			ans[0][pt]='.';ans[1][pt++]='#';
		}
		for (int i=0;i<nud.size();i++)
		{
			ans[0][pt]='.';ans[1][pt++]='.';
		}
		puts(ans[0]);puts(ans[1]);
		return 0;
	}
	if (u.size()&&d.size()&&!ud.size()) return puts("NO"),0;
	puts("YES");
	int pt=0;
	for (int i=0;i<u.size();i++)
	{
		ans[0][pt]='#';ans[1][pt++]='.';
	}
	for (int i=0;i<ud.size();i++)
	{
		ans[0][pt]='#';ans[1][pt++]='#';
	}
	for (int i=0;i<d.size();i++)
	{
		ans[0][pt]='.';ans[1][pt++]='#';
	}
	for (int i=0;i<nud.size();i++)
	{
		ans[0][pt]='.';ans[1][pt++]='.';
	}
	puts(ans[0]);puts(ans[1]);
	return 0;
}