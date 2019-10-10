#include <cstdio>
#include <cstring>
#define MAXN 1000005
using namespace std;

char s[MAXN],t[MAXN];
int T,nxt[MAXN];

inline void getNext(char S[])
{
	int i = 0, j = -1, len = strlen(S);
	nxt[0] = -1;
	while (S[i])
	{
		if (!~j || S[i] == S[j]) nxt[++i] = ++j;
		else j = nxt[j];
	}
	return ;
}

inline int KMP(char S[], char T[])
{
	int ans = 0;
	int i = 0, j = 0, lb = strlen(S), la = strlen(T);
	while (i < lb && j < la)
	{
		if (!~j || S[i] == T[j])
		{
			++i; ++j;
			if (j == la)
			{
				++ans; j = nxt[j - 1]; --i;
			}
		}
		else j = nxt[j];
	}
	return ans;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",t);getNext(t);
		scanf("%s",s);printf("%d\n",KMP(s,t));
	}
	return 0;
}