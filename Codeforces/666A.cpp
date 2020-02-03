#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=998244353,mod=119;
const int Lim=1<<20;

string s;
set<string> st;
bool ok[MAXN];

int main()
{
	cin>>s;
	int sz=SZ(s);
	ok[sz]=1;
	for(int i=sz-2;i>4;i--)
	{
		string pt;pt.clear();
		pt+=s[i];
		for(int len=2;len<=3;len++)
		if(i+len-1<sz)
		{
			pt+=s[i+len-1];
			if(ok[i+len])
			{
				if(ok[i+5]||s.find(pt,i+len)!=i+len)
				{
					st.insert(pt);
					ok[i]=1;
				}
			}
		}
	}
	printf("%d\n",SZ(st));
	for(auto j:st)
		cout<<j<<"\n";
	return 0;
}
