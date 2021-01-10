#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n;
char s[100000];
map <int,string> mp;

string getStr(int x)
{
	if (mp.count(x)) return mp[x];
	char s[16];memset(s,0,sizeof s);
	int p=x,l=0;
	for (;p;p>>=1) ++l;
	for (int i=0;i<l;i++) s[i]=(x>>i&1)+'0';
	reverse(s,s+l);
	string ans="";
	int lst=0;
	for (int i=1;i<l;i++)
	{
		if (s[i]!=s[i-1])
		{
			if (ans.size()&&i-lst!=1&&ans.back()!='+') ans+='+';
			string p=getStr(i-lst);
			ans+=s[i-1];
			ans+=p;
			if (i-lst!=1) ans+='+';
			lst=i;
		}
	}
	if (ans.size()&&l-lst!=1&&ans.back()!='+') ans+='+';
	string pp=getStr(l-lst);
	ans+=s[l-1];
	ans+=pp;
	return '('+ans+')';
}

inline void Solve()
{
	scanf("%d",&n);
	scanf("%s",s);
	int lst=0;
	string ans="";
	for (int i=1;i<n;i++)
	{
		if (s[i]!=s[i-1])
		{
			if (ans.size()&&i-lst!=1&&ans.back()!='+') ans+='+';
			string p=getStr(i-lst);
			ans+=s[i-1];
			ans+=p;
			if (i-lst!=1) ans+='+';
			lst=i;
		}
	}
	if (ans.size()&&n-lst!=1&&ans.back()!='+') ans+='+';
	string p=getStr(n-lst);
	ans+=s[n-1];
	ans+=p;
	if (ans.size()<n) puts("YES");
	else puts("NO");
	cout<<ans<<'\n';
	return ;
}

int main()
{
	mp[1]="";
	int T;
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}