#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e5+10,MAXM=1e6+10;
const int INF=0x7fffffff;
const int MOD=20100403;
 
int h[5],a[5],d[5];
 
int main()
{
	for(int i=1;i<=3;i++)
		scanf("%d%d%d",&h[i],&a[i],&d[i]);
	int ans=INF;
	for(int i=0;i<=200;i++)
		for(int j=0;j<=100;j++)
			for(int k=0;k<=1000;k++)
			{
				if(a[1]+i<=d[2])continue;
				int tim=(h[2]-1)/(a[1]+i-d[2])+1;
				if(k+h[1]>tim*(a[2]-d[1]-j)){
					ans=min(ans,k*h[3]+i*a[3]+j*d[3]);
				}
			}
	cout<<ans<<endl;
	return 0;
}
