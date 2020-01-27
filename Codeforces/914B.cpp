#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[100050];
int cnt[100050];

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],cnt[a[i]]++;
	for(int i=1;i<=100000;++i)
	{
		if(cnt[i]&1)return puts("Conan"),0;
	}
	puts("Agasa");
	return 0;
}