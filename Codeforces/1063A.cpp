#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
using namespace std;
const int N=100050;
int n;
char s[N];
int a[30];

int main()
{
	cin>>n;
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		a[s[i]-'a']++;
	}
	for(int i=0;i<26;++i)
		for(int j=1;j<=a[i];++j)
			printf("%c",i+'a');
	return 0;
}