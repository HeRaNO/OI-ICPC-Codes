#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T,a[20];
	cin>>T;int x=1;string s;
	while (T--)
	{
		int cnt=0,l;
		cout<<"Case # "<<x<<':'<<'\n';
		cin>>s;
		for (int i=0;i<s.length();i++) a[i]=i;
		do{
			for (int i=0;i<s.length();i++)
				printf("%c",s[a[i]]);
			putchar('\n');
		}while(next_permutation(a,a+s.length()));
		++x;
	}
	return 0;
}