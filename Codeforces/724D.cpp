#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define mp(a,b) make_pair(a,b)
using namespace std;
const int N=100050;
char s[N];
int cnt[30];
int n,m,now;
int pos[N],tot;
int pos2[N],tot2;
inline char id(int x){return x+'a';}

bool check(int x)
{
	int lst,pos;lst=now=pos=0;
	for(int i=1;i<=m;++i)
	{
		if(s[i]==id(x))pos=i;
		else if(s[i]<id(x))lst=i;
		if(i-lst>=n)
		{
			if(i-pos<n)lst=pos,now++;
			else return false;
		}
	}
	return true;
}

int main()
{
	cin>>n;
	scanf("%s",s+1);
	m=strlen(s+1);
	for(int i=1;i<=m;++i)cnt[s[i]-'a']++;
	for(int i=0;i<26;++i)
	{
		if(check(i))
		{
			for(int j=0;j<i;++j)for(int k=0;k<cnt[j];++k)
			printf("%c",j+'a');
			for(int j=1;j<=now;++j)printf("%c",i+'a');
			break;
		}
	}
	return 0;
}
