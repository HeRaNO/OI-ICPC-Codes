#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define pb(x) push_back(x)
#define Sort(x) sort(s[x].begin(),s[x].end())
using namespace std;
const int N=300050;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
int n,k;
int wildcard;
int wildcard_cnt;
unordered_map <char,int> h;
unordered_map <int,char> H;
void Init()
{
	h['A']=1;
	for(char i='2';i<='9';++i)h[i]=i-'0';
	h['D']=10;h['Q']=11;h['J']=12;h['K']=13;
	H[1]='A';
	for(int i=2;i<=9;++i)H[i]=i+'0';
	H[10]='D';H[11]='Q';H[12]='J';H[13]='K';
}
int nxtid(int id){id++;id%=n;if(id==0)id=n;return id;}
string s[20];
int cnt[20][20];
bool yesEqual(int id)
{
	return (s[id][0]==s[id][1]&&s[id][1]==s[id][2]&&s[id][2]==s[id][3]);
}
void work(int id)
{
	Sort(id);
	mem(cnt[id],0);
	if(wildcard==id)
	{
		if(wildcard_cnt==1)
		{
			wildcard=nxtid(wildcard);
			wildcard_cnt=0;
			return;
		}
	}
	if(wildcard==id)wildcard_cnt++;
	for(auto c:s[id])cnt[id][h[c]]++;
	int mx=999;char cc=0;
	for(int i=1;i<=13;++i)
	{
		if(cnt[id][i]==0)continue;
		if(cnt[id][i]<mx)
		{
			mx=cnt[id][i];
			cc=H[i];
		}
	}
	s[nxtid(id)].push_back(cc);
	auto it=s[id].find(cc);
	s[id].erase(s[id].begin()+it);
}

int check(int id)
{
	int t1=999,t2=999;
	int nxt=nxtid(id);
	if(wildcard!=id&&s[id].size()==4)
	{
		if(yesEqual(id))
			t1=h[s[id][0]];
	}
	if(wildcard!=nxt&&s[nxt].size()==4)
	{
		if(yesEqual(id))
			t2=h[s[id][0]];
	}
	if(t1<t2)return id;
	else if(t1>t2)return nxt;
	else return -1;
}

int main()
{
	Init();
	cin>>n>>k;
	wildcard=k;
	for(int i=1;i<=n;++i)cin>>s[i];
	for(int i=1;i<=n;++i)Sort(i);
	int mx=999,ansid=0;
	for(int i=1;i<=n;++i)
	{
		if(i==k)continue;
		if(yesEqual(i)&&mx>h[s[i][0]])
		{
			mx=h[s[i][0]];
			ansid=i;
		}
	}
	if(ansid)return printf("%d\n",ansid),0;
	while(true)
	{
		work(k);
		int now=check(k);
		if(now!=-1)
		{
			printf("%d\n",now);
			break;
		}
		k=nxtid(k);
	}
	return 0;
}
