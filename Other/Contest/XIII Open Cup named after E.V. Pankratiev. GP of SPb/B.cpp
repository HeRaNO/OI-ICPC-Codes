#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1e6+150,INF=0x7fffffff;

char s[MAXN];
char b[MAXN];
int _next[MAXN];
int sz,ini,ans;

void check()
{
	_next[1]=0;
	int bs=sz-2;
	for(int i=1;i<bs;i++)
	{
		int temp=i;
		do
		{
			temp=_next[temp];
			if(b[temp]==b[i])
			{
				_next[i+1]=temp+1;
				break;
			}
		}
		while(temp);
	}
	int maxn=0;
	for(int j=0;j<=bs;j++)
	{
		int i=j;
		i=_next[i];
		if(i>maxn)
		{
			maxn=i;
			ans=j-i;
			ini=sz-j;
		}
	}
}

int main()
{
	freopen("decimal.in","r",stdin);
	freopen("decimal.out","w",stdout);
	scanf("%s",s);
	if(s[0]=='1')
	{
		cout<<"1.(0)";
	}
	else
	{
		sz=strlen(s);
		for(int i=0;i<sz-2;i++)
			b[i]=s[sz-i-1];
		b[sz-2]='\0';
		check();
		if(ini==0)
		{
			printf("0.(");
			for(int i=2;i<sz;i++)printf("%c",s[i]);
		}
		else
		{
			printf("0.");
			for(int i=2;i<ini;i++)
				printf("%c",s[i]);
			printf("(");
			for(int i=ini;i<ans+ini;i++)
				printf("%c",s[i]);
		}
		printf(")");
	}
	return 0;
}

/*
0.9999999
0.63573573
0.123456789
*/
