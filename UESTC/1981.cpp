#include <bits/stdc++.h>
using namespace std;

int T;string p;set<string> s;

int main()
{
	cin>>T;
	while (T--){cin>>p;s.insert(p);}
	printf("%d\n",s.size());
	return 0;
}
