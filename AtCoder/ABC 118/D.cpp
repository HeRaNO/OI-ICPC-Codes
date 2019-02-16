#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

const int c[]={0,2,5,5,4,5,6,3,7,6};

int n,m,a[10];
string f[MAXN];

bool g(string &a,string &b)
{
	if (a.length()!=b.length()) return a.length()>b.length();
	for (int i=0;i<a.length();i++)
		if (a[i]!=b[i]) return a[i]>b[i];
	return true;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			int k=i-c[a[j]];
			if (k<0) continue;
			if (k>0&&f[k]=="") continue;
			string p="";p.push_back(a[j]+'0');
			if (a[j]>=f[k][0]-'0') p=p+f[k];
			else p=f[k]+p;
			if (g(p,f[i])) f[i]=p;
		}
	cout<<f[n]<<endl;
	return 0;
}