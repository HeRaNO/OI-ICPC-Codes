#include <bits/stdc++.h>
using namespace std;

int n,cnt;long long k,b;
string s;

int main()
{
	cin>>n>>k;--k;
	cin>>s;
	putchar((__builtin_popcountll(k/n)&1)^(s[k%n]-'0')+'0');
	putchar('\n');
	return 0;
}