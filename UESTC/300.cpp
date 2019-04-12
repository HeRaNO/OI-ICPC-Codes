#include <bits/stdc++.h>
#define MAXN 105
#define fi first
#define se second
#define mp make_pair
using namespace std;

int T,n,l,cnt;char d[3];
pair<int,string> a[MAXN];
pair<int,bool> b[MAXN];

int main()
{
	cin>>T;
	while (T--)
	{
		cin>>n>>l;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i].se>>a[i].fi>>d;
			if (d[0]=='L') b[i]=mp(a[i].fi,false);
			else b[i]=mp(l-a[i].fi,true);
		}
		sort(a+1,a+n+1);sort(b+1,b+n+1);
		int L=1,R=n;
		cout<<"Case #"<<++cnt<<":\n";
		for (int i=1;i<=n;i++)
		{
			if (!b[i].se) cout<<b[i].fi<<' '<<a[L++].se<<'\n';
			else cout<<b[i].fi<<' '<<a[R--].se<<'\n';
		}
	}
	return 0;
}
