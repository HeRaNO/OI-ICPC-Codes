#include <cstdio>
#include <cstring>
#define MAXN 1000010
using namespace std;

char S[MAXN], T[MAXN];
int p[MAXN];

inline int mymin(int a, int b)
{
	return a < b ? a : b;
}
inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

inline void Build(char S[], char T[])
{
	int Slen = strlen(S + 1);
	T[0] = '$';
	T[1] = '#';
	for (int i = 1; i <= Slen; i++) T[i << 1] = S[i], T[(i << 1) + 1] = '#';
	return ;
}

inline int Manacher(char S[])
{
	int Slen = strlen(S + 1), mx = 0, res = 0, id = 0;
	memset(p, 0, sizeof p);
	for (int i = 1; i <= Slen; i++)
	{
		if (mx > i) p[i] = mymin(p[(id << 1) - i], mx - i);
		else p[i] = 1;
		while (S[i + p[i]] == S[i - p[i]]) p[i]++;
		if (mx < i + p[i]) mx = i + p[i], id = i;
	}
	for (int i = 1; i <= Slen; i++) res = mymax(res, p[i]);
	return res - 1;
}

int main()
{
	scanf("%s", S + 1);
	Build(S, T);
	printf("%d\n", Manacher(T));
	return 0;
}
