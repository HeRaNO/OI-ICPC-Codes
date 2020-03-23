#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,m,k;
bool a[MAXN],b[MAXN];
string ans;

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<m;i++) ans+='L';
	for (int i=1;i<n;i++) ans+='U';
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<m;j++) ans+=(i&1)?'R':'L';
		ans+='D';
	}
	printf("%d\n",ans.size());
	cout<<ans<<endl;
	return 0;
}
