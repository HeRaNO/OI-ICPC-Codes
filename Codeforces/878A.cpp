#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=5e5+10,MAXM=1e6+10;
const int INF=~(1<<31),MOD=1e9+7;

char a[MAXN][2];
int num[MAXN];
int ans[50][2],n;
int nn[5];

int calc(int t,int loc)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i][0]=='|')t|=num[i];
		else if(a[i][0]=='&')t&=num[i];
		else if(a[i][0]=='^')t^=num[i];
	}
	return (t>>loc)&1;
}
 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s%d",a[i],&num[i]);
	for(int i=0;i<10;i++)
	{
		ans[i][0]=calc(0,i);
		ans[i][1]=calc((1<<i),i);
	}
	for(int i=0;i<10;i++)
	{
		if(ans[i][0]&&ans[i][1])
		{
			nn[1]|=(1<<i);
		}
		else if(ans[i][0]==1&&ans[i][1]==0)
		{
			nn[2]|=(1<<i);
		}
		if(!(ans[i][0]==0&&ans[i][1]==0))
		{
			nn[0]^=(1<<i);
		}
	}
	int cnt=0;
	for(int i=1;i<=2;i++)if(nn[i])cnt++;
	if(nn[0]!=1023)cnt++;
	printf("%d\n",cnt);
	if(nn[0]!=1023)printf("& %d\n",nn[0]);
	if(nn[1])printf("| %d\n",nn[1]);
	if(nn[2])printf("^ %d\n",nn[2]);
	return 0;
}