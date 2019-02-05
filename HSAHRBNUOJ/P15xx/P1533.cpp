#include <cmath>
#include <cstdio>
#define MAXN 1000000
using namespace std;

unsigned int A[MAXN], B[MAXN];
double inv[MAXN];

unsigned int min(unsigned int a,unsigned int b){return a<b?a:b;}

unsigned int get(unsigned int n)
{
	if (n<2) return 0;
	unsigned int lim = sqrt(n) + 1;
	if(n <= 10) return (n >= 2) + (n >= 3) + (n >= 5) + (n >= 7);
	for(int i = 1; i <= lim; i++) inv[i] = 1. / i, A[i] = (n / i + 1) / 2, B[i] = (i + 1) / 2 - (i == 1);
	for(int i = 3; i <= lim; i++) if(B[i] != B[i - 1]) {
		unsigned int l = B[i - 1], j = 1;
		for( ; i * j <= lim; j += 2) A[j] -= A[i * j] - l;
		double tmp = n / i;
		for(int s = min(n / i / i, lim); j <= s; j += 2) A[j] -= B[(int) (tmp * inv[j] + 1e-7)] - l;
		for(int j = lim / i; j >= i; j--)
		for(int k = 0; k < i; k++) B[j * i + k] -= B[j] - l;
	}
	return A[1];
}

int main()
{
	int l,r;scanf("%d %d",&l,&r);
	printf("%u\n",get(r)-get(l-1));
	return 0;
}
