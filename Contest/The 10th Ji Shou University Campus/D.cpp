#include <bits/stdc++.h>
using namespace std;

char s[2000005];
int n;

inline int getPoint(char x)
{
	if (x=='J') return 10;
	if (x=='Q') return 11;
	if (x=='K') return 12;
	if (x=='A') return 1;
	return x-'0';
}

stack <char> sta;
int ap[250];

int main(int argc, char const *argv[])
{
	scanf("%s",s);n=strlen(s);
	int z=0,lb=0;
	for (int i=0;i<n;i++)
	{
		int cnt=0;
		if (ap[s[i]])
		{
			assert(ap[s[i]]==1);
			while (!sta.empty()&&sta.top()!=s[i])
			{
				cnt+=getPoint(sta.top());
				--ap[sta.top()];
				sta.pop();
			}
			cnt+=2*getPoint(sta.top());
			--ap[sta.top()];
			sta.pop();
			if (i&1) lb+=cnt;
			else z+=cnt;
		}
		else
		{
			sta.push(s[i]);
			++ap[s[i]];
		}
	}
	if (z>lb) printf("zqc %d\n",z);
	else if (z==lb) puts("-1");
	else printf("lbg %d\n",lb);
	return 0;
}