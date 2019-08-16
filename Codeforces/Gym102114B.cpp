#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;

int b[20],a;
int ans1[20],ans2[20],cnt;

void fenjie(int a)
{
	cnt=0;
	while(a)
	{
		b[++cnt]=a%10;
		a/=10;
	}
	return;
}

int hecheng()
{
	int ans=0;
	for(int i=cnt;i>=1;i--)
	{
		ans*=10;
		ans+=b[i];
	}
	return ans;
}

int dfs(int num,int depth,int total)
{
	if(depth==total||cnt<depth)
		return num;
	int ans=0;
	fenjie(num);
	int maxn=b[cnt-depth+1]+1;
	for(int i=cnt-depth;i>=1;i--)
		maxn=max(maxn,b[i]);
	for(int i=cnt-depth;i>=1;i--)
		if(b[i]==maxn)
		{
			swap(b[cnt-depth+1],b[i]);
			ans=max(ans,dfs(hecheng(),depth+1,total));
			swap(b[cnt-depth+1],b[i]);
		}
		ans=max(ans,dfs(hecheng(),depth+1,total+1));
	return ans;
}

int dfs2(int num,int depth,int total)
{
	//cout<<depth<<" "<<cnt<<" "<<total<<endl;
	if(depth==total||depth>cnt)
		return num;
	int ans=0x7fffffff;
	fenjie(num);
	int minn=b[cnt-depth+1]-1;
	for(int i=cnt-depth;i>=1;i--)
		if(b[i]||(!b[i]&&depth!=1))
		minn=min(minn,b[i]);
	for(int i=cnt-depth;i>=1;i--)
		if(b[i]==minn&&(b[i]||(!b[i]&&depth!=1)))
		{
			swap(b[cnt-depth+1],b[i]);
			ans=min(ans,dfs2(hecheng(),depth+1,total));
			swap(b[cnt-depth+1],b[i]);
		}
	ans=min(ans,dfs2(hecheng(),depth+1,total+1));
	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&a);
		int n;
		scanf("%d",&n);
		fenjie(a);
		int maxn=dfs(a,1,min(n,9)+1);
		fenjie(a);
		int minn=dfs2(a,1,min(n,9)+1);
		printf("%d %d\n",minn,maxn);
	}
	return 0;
}