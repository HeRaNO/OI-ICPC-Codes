#include <cstdio>
#include <vector>
#include <algorithm>

int fmul(int x, int y, int p){ return 1LL * x * y % p; }

void f(std::vector<int> &a, int seed, int n, int k, int p)
{
	a[0] = seed % k;
	for(int i = 1; i < n; i++) a[i] = fmul(a[i - 1], p, k);
	return ;
}

int phi(int x)
{
	int res = x;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
		{
			res /= i;
			res *= (i - 1);
			while (x % i == 0) x /= i;
		}
	if (x != 1) res /= x, res *= (x - 1);
	return res;
}

int Kmod(std::vector<int> &A, int k, int p)
{
	int r = 0;
	for (int i : A) r = (1LL * r * k + i) % p;
	return r;
}

bool lt(std::vector<int> &A, std::vector<int> &B)
{
	if (A.size() != B.size())
		return A.size() < B.size();
	int n = A.size();
	for (int i = 0; i < n; i++)
		if (A[i] != B[i]) return A[i] < B[i];
	return true;
}

int dec(std::vector<int> &A, int k)
{
	int r = 0;
	for (int i : A)
	{
		if (1LL * r * k + i > 1'000'000'000)
			while (1);
		r = r * k + i;
	}
	return r;
}

int fpow(int a, int b, int p)
{
	int r = 1 % p;
	for (; b; b >>= 1, a = fmul(a, a, p)) if (b & 1) r = fmul(r, a, p);
	return r;
}

int main()
{
	int seed, n, ka, p;
	scanf("%d %d %d %d", &seed, &n, &ka, &p);
	std::vector<int> A(n);
	f(A, seed, n, ka, p);
	int kb;
	scanf("%d %d %d %d", &seed, &n, &kb, &p);
	std::vector<int> B(n);
	f(B, seed, n, kb, p);
	int C;
	scanf("%d", &C);
	if (C == 1) return puts("0"), 0;
	int phi_C = phi(C);
	std::vector<int> phi_C_k;
	for (int i = phi_C; i; i /= kb)
		phi_C_k.push_back(i % kb);
	std::reverse(phi_C_k.begin(), phi_C_k.end());
	int x = Kmod(A, ka, C), y;
	if (lt(B, phi_C_k))
		y = dec(B, kb);
	else
		y = Kmod(B, kb, phi_C) + phi_C;
	printf("%d\n", fpow(x, y, C));
	return 0;
}