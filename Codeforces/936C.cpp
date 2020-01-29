#include <bits/stdc++.h>
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define ls id<<1
#define rs id<<1|1
using namespace std;
const int N=2050;
int n;
char s[N],t[N],tmp[N];
int ans[N*3];
void rev(int x)
{
	if(x==0)return;
	reverse(s+1,s+n+1);
	reverse(s+x+1,s+n+1);
	ans[++ans[0]]=x;
}
int A[30];
int B[30];

int main()
{
	cin>>n;
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1;i<=n;++i)A[s[i]-'a']++,B[t[i]-'a']++;
	for(int i=0;i<30;++i)if(A[i]!=B[i])return puts("-1"),0;
	for(int i=1;i<=n;++i)
	{
		int j;
		for(j=i;j<=n;++j)if(s[j]==t[n-i+1])break;
		if(j==n+1)return puts("-1"),0;
		rev(n);rev(j-1);rev(1);
	}
	printf("%d\n",ans[0]);
	for(int i=1;i<=ans[0];++i)printf("%d ",ans[i]);
	return 0;
}