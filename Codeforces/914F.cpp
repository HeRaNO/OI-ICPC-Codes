#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

int n;
char s[MAXN],t[MAXN];

bitset<100005> ch[26],ans;

int main()
{
	scanf("%s",s);
	int sz=strlen(s);
	for(int i=0;i<sz;i++)
		ch[s[i]-'a'].set(i);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int o;
		scanf("%d",&o);
		if(o==1)
		{
			char ss[5];
			int pos;
			scanf("%d%s",&pos,ss);
			pos--;
			char p=ss[0];
			ch[s[pos]-'a'].reset(pos);
			ch[p-'a'].set(pos);
			s[pos]=p;
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			scanf("%s",t);
			int ssz=strlen(t);
			if(ssz>r-l+1)
			{
				puts("0");
				continue;
			}
			ans.set();
			for(int i=0;i<ssz;i++)
				ans&=(ch[t[i]-'a']>>i);
			printf("%d\n",(int)((ans>>(l-1)).count()-(ans>>(r-ssz+1)).count()));
		}
	}
	return 0;
}
