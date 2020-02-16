#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int nxt[MAXN],nxtt[MAXN],ls,lt,n;
char S[MAXN],T[MAXN];

inline void GetNext()
{
	int i = 0, j = -1;
	nxt[0] = -1;
	while (i != lt)
	{
		if (!~j || T[i] == T[j]) nxt[++i] = ++j;
		else j = nxt[j];
	}
	return ;
}

inline void GetNext2()
{
	int i = 0, j = -1;
	nxtt[0] = -1;
	while (i != ls)
	{
		if (!~j || S[i] == S[j]) nxtt[++i] = ++j;
		else j = nxtt[j];
	}
	return ;
}

inline bool KMP()
{
	int i = 0, j = 0;
	while (i < ls && j < lt)
	{
		if (!~j || S[i] == T[j])
		{
			++i; ++j;
			if (j == lt) return true;
		}
		else j = nxt[j];
	}
	return false;
}

inline bool KMP2()
{
	int i = 0, j = 0;
	while (i < lt && j < ls)
	{
		if (!~j || S[j] == T[i])
		{
			++i; ++j;
			if (j == ls) return true;
		}
		else j = nxtt[j];
	}
	return false;
}

int main()
{
	scanf("%s",T);lt=strlen(T);GetNext();
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",S);ls=strlen(S);
		if (lt<ls)
		{
			if (KMP()) puts("my teacher!");
			else puts("senior!");
		}
		else if (lt>ls)
		{
			GetNext2();
			if (KMP2()) puts("my child!");
			else puts("oh, child!");
		}
		else
		{
			bool f=true;
			for (int i=0;i<ls&&f;i++) if (S[i]!=T[i]) f=false;
			if (f) puts("jntm!");
			else puts("friend!");
		}
	}
	return 0;
}