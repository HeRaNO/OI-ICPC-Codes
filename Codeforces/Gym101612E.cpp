#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF=~(1<<31),MAXN=1e6+10;

int num[MAXN];
vector <int>v1,v2;
int res[MAXN];
int tmp[MAXN];

int main()
{
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		num[temp]++;
	}
	int ans=0;
	for(int i=1;i<=1e6;i++)
		if(num[i])
		{
			ans++;
			bool ok=0;
			for(int j=2;j*i<=1e6;j++)
				if(num[i*j])
				{
					ok=1;
					break;
				}
			if(ok)v1.push_back(num[i]);
			else v2.push_back(num[i]);
		}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	printf("%d ",ans);
	res[0]=tmp[0]=ans;
	int now=0;
	memset(tmp,0x3f,sizeof(tmp));
	for(int i=0;i<v1.size();i++)
		res[(now+=v1[i])]--;
	for(int i=1;i<=n;i++)
		res[i]+=res[i-1];
	if(v2.size()>=2)
	{
		memset(tmp,0,sizeof(tmp));
		tmp[0]=res[0];
		int mval=v2[0]+v2[1];
		now=mval;
		tmp[now]--;
		int cnt1=0,cnt2=2;
		while(cnt1<v1.size()||cnt2<v2.size())
		{
			if(cnt1>=v1.size()&&cnt2<v2.size())tmp[(now+=v2[cnt2])]--,cnt2++;
			else if(cnt2>=v2.size()&&cnt1<v1.size())tmp[(now+=v1[cnt1])]--,cnt1++;
			else if(v1[cnt1]<v2[cnt2])tmp[(now+=v1[cnt1])]--,cnt1++;
			else tmp[(now+=v2[cnt2])]--,cnt2++;
		}
		for(int i=1;i<=n;i++) tmp[i]+=tmp[i-1];
	}
	for(int i=1;i<=n;i++)
		printf("%d ",min(tmp[i],res[i]));
	return 0;
}