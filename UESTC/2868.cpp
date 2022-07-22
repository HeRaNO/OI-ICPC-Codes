#include <cstdio>
using namespace std;

const int M=998244353;
const int _2=(M+1)/2;

inline int mul(int a,int b){return 1LL*a*b%M;}
inline void fadd(int &a,int b){a+=b;if (a>=M) a-=M;return ;}

inline void Solve()
{
	int n,p=0;
	scanf("%d",&n);
	for (int i=0;i<4;i++)
		for (int j=0,x;j<2;j++)
		{
			scanf("%d",&x);
			fadd(p,x);
		}
	printf("%d\n",mul(mul(n-1,p),_2));
	return ;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--) Solve();
	return 0;
}