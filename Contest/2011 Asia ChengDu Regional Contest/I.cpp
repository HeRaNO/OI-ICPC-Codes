#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (id<<1)
#define rs (id<<1|1)
#define Rint register int
#define UNI(x) sort(ALL(x)),x.resize(unique(ALL(x))-x.begin())
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
const int MAXN=2e6+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1004535809,mod=998244353;
const int inv2=5e8+4;
const int Lim=1<<20;

int n;
char s[55][55];
char t[55][55];
vector<string> v;
vector<string> all;

void rotatee()
{
	char tmp[55][55];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)tmp[i][j]=t[n-j+1][i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)t[i][j]=tmp[i][j];
}

vector<string> ans;

void solve()
{
	ans.resize(0);
	v.resize(0);
	all.resize(0);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)scanf("%s",t[i]+1);
	for(int i=0;i<4;i++)
	{
		string tmp;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(t[i][j]=='*')tmp+=s[i][j];
			}
		all.pb(tmp);
		rotatee();
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		string c;
		cin>>c;
		v.pb(c);
	}
	for(int _=0;_<4;_++)
	{
		string tmp;
		for(int i=0;i<4;i++)tmp+=all[(i+_)%4];
		tmp+='.';
		int lst=0,f=0;
		vector<string>t;
		for(int i=0;i<SZ(tmp);i++)
		{
			if(tmp[i]=='.')
			{
				if(i>lst)
				{
					string c=tmp.substr(lst,i-lst);
					t.pb(c);
					bool ok=0;
					for(auto j:v)if(j==c){ok=1;break;}
					if(!ok)f=1;
				}
				lst=i+1;
			}
			if(f)break;
		}
		if(!f)
		{
			string ANS;
			for(int i=0;i<SZ(t)-1;i++)ANS+=t[i],ANS+=' ';
			ANS+=t.back();
			ans.pb(ANS);
		}
	}
	if(!SZ(ans))puts("FAIL TO DECRYPT");
	else cout<<*min_element(ALL(ans))<<"\n";
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{printf("Case #%d: ",i);solve();}
	return 0;
}