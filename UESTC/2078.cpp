#include <cstdio>
#include <cstring>
#define MAXN 1000010

char a[MAXN],b[MAXN];
int la,lb,nxt[MAXN];

inline void GetNext(char S[])
{
	int i = 0, j = -1, len = strlen(S);
	nxt[0] = -1;
	while (i != len)
	{
		if (!~j || S[i] == S[j]) nxt[++i] = ++j;
		else j = nxt[j];
	}
	return ;
}

inline int KMP(char S[], char T[])
{
	int ans = 0;
	int i = 0, j = 0;
	while (i < la && j < lb)
	{
		if (!~j || S[i] == T[j])
		{
			++i; ++j;
			if (j == lb)
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
	scanf("%s",a);scanf("%s",b);
	la=strlen(a);lb=strlen(b);
	GetNext(b);printf("%d\n",KMP(a,b));	
	return 0;
}
