#include <bits/stdc++.h>
using namespace std;

int T,n,cnt;
string s,m,k;

int main()
{
	cin>>T;getline(cin,s);
	while (T--)
	{
		cin>>n;getline(cin,s);
		getline(cin,m);cnt=0;
		for (int i=1;i<=n;i++)
		{
			getline(cin,s);
			int p=0;bool f=false;
			while (p<s.length()&&!f)
			{
				while (!isalpha(s[p])&&p<s.length()) ++p;
				int t=0,q=p;
				while (isalpha(s[q])&&q<s.length()) ++t,++q;
				k=s.substr(p,t);
				if (k==m) f=true;
				p=q;
			}
			if (f) ++cnt;
		}
		if (cnt) cout<<cnt<<'\n'<<'\n';
		else cout<<"Do not find"<<'\n'<<'\n';
	}
	return 0;
}
