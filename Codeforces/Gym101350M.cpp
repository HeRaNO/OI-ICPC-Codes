#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

map <string,double> mp;
int T,c,n,nal;
double p,ans;
char na[10];
string name;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		mp.clear();ans=0;
		scanf("%d %d",&c,&n);
		for (int i=1;i<=c;i++)
		{
			scanf("%s %lf",na,&p);name="";nal=strlen(na);
			for (int j=0;j<nal;j++) name.push_back(na[j]);
			mp.insert(make_pair(name,p));
		}
		mp.insert(make_pair("JD",1.000));
		for (int i=1;i<=n;i++)
		{
			scanf("%lf %s",&p,na);name="";nal=strlen(na);
			for (int j=0;j<nal;j++) name.push_back(na[j]);
			ans+=mp[name]*p;
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}