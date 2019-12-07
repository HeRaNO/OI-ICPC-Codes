#include <bits/stdc++.h>
using namespace std;

string s;
int n,ans;

int main()
{
	cin>>s;n=s.length();
	for (int i=0;i<=n-10;i++)
		if (s.substr(i,10)=="NicoNicoNi") ++ans;
	printf("NicoNicoNi * %d\n",ans);
	return 0;
}