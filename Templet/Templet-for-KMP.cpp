#include <cstdio>
#include <cstring>
#define MAXN 1000010
using namespace std;

int nxt[MAXN], exnxt[MAXN], ext[MAXN];
char S[MAXN];

/*
	nxt[i] is the max number which can make S[0..nxt[i]-1]==S[i-nxt[i]..i-1]
	exnxt[i] is the max number which can make S[0..exnxt[i]]==S[i..i+exnxt[i]-1]
	ext[i] is the max number which can make S[i..i+ext[i]-1]==T[0..ext[i]-1]
*/

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}

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

inline void GetExtendNext(char S[])
{
	int a = 0, Slen = strlen(S);
	exnxt[0] = Slen;
	while (a < Slen && S[a] == S[a + 1]) a++;
	exnxt[1] = a;
	a = 1;
	for (int i = 2; i < Slen; i++)
	{
		int p = a + exnxt[a] - 1, l = exnxt[i - a];
		if (i - 1 + l >= p)
		{
			int j = (p - i + 1) > 0 ? p - i + 1 : 0;
			while (i + j < Slen && S[i + j] == S[j]) j++;
			exnxt[i] = j;
			a = i;
		}
		else exnxt[i] = l;
	}
	return ;
}

inline void GetExtend(char S[], char T[])
{
	int a = 0;
	GetExtendNext(T);
	int Slen = strlen(S), Tlen = strlen(T);
	int Minlen = mymin(Slen, Tlen);
	while (a < Minlen && S[a] == T[a]) a++;
	ext[0] = a;
	a = 0;
	for (int i = 1; i < Slen; i++)
	{
		int p = a + ext[a] - 1, l = exnxt[i - a];
		if (i - 1 + l >= p)
		{
			int j = (p - i + 1) > 0 ? p - i + 1 : 0;
			while (i + j < Slen && j < Tlen && S[i + j] == T[j]) j++;
			ext[i] = j;
			a = i;
		}
		else ext[i] = l;
	}
	return ;
}

int main()
{
	return 0;
}
