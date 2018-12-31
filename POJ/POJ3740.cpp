#include <cstdio>
#include <climits>
#define MAXN 5010
using namespace std;

int n, m;
int L[MAXN], U[MAXN], R[MAXN], D[MAXN], S[MAXN], C[MAXN], H[MAXN];
int cnt, head;
int in;

void prepare()
{
	cnt = m;
	for (int i = 0; i <= cnt; i++)
	{
		C[i] = U[i] = D[i] = i;
		L[i + 1] = i;
		R[i] = i + 1;
		S[i] = 0;
	}
	L[0] = m;
	R[m] = 0;
	return ;
}

void add(int i, int j)
{
	C[++cnt] = j;
	S[j]++;
	D[cnt] = j;
	U[cnt] = U[j];
	if (H[i]) R[cnt] = H[i], L[cnt] = L[H[i]];
	else R[cnt] = L[cnt] = cnt;
	H[i] = cnt;
	U[D[cnt]] = D[U[cnt]] = cnt;
	L[R[cnt]] = R[L[cnt]] = cnt;
	return ;
}

void remove(int c)
{
	R[L[c]] = R[c];
	L[R[c]] = L[c];
	for (int i = D[c]; i != c; i = D[i])
		for (int j = R[i]; j != i; j = R[j])
		{
			U[D[j]] = U[j];
			D[U[j]] = D[j];
			S[C[j]]--;
		}
	return ;
}

void resume(int c)
{
	for (int i = U[c]; i != c; i = U[i])
		for (int j = L[i]; j != i; j = L[j])
		{
			D[U[j]] = U[D[j]] = j;
			S[C[j]]++;
		}
	L[R[c]] = R[L[c]] = c;
	return ;
}

bool Dancing_Link_X()
{
	if (R[head] == head)
	{
		puts("Yes, I found it");
		return true;
	}
	int s = INT_MAX, c;
	for (int i = R[head]; i != head; i = R[i])
		if (S[i] < s) s = S[i], c = i;
	remove(c);
	for (int i = D[c]; i != c; i = D[i])
	{
		for (int j = R[i]; j != i; j = R[j]) remove(C[j]);
		if (Dancing_Link_X()) return true;
		for (int j = L[i]; j != i; j = L[j]) resume(C[j]);
	}
	resume(c);
	return false;
}

int main()
{
	while (~scanf("%d %d", &n, &m))
	{
		prepare();
		for (int i = 1; i <= n; i++)
		{
			H[i] = 0;
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", &in);
				if (in) add(i, j);
			}
		}
		if (!Dancing_Link_X()) puts("It is impossible");
	}
	return 0;
}
