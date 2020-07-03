#include <bits/stdc++.h>
using namespace std;

const int M=1000000007;
const int fib[]={1,3,21,987,2178309,209783453,700290221,745621702,330235873,754854590,961030536,124518512,198180511,314263529,787294282,269256820,462470690,139070082,932065818,580737058,545755243,798765759,810968381,635507288,251205278,445892347,804101592,699722224,900885101,912848361};

int T,n;

inline void fadd(int &a,int b){a+=b;if (a>=M) a-=M;return ;}

inline int f(int n)
{
	int ans=0;
	for (int i=0;(1<<i)<=n;i++)
	{
		int t=n/(1<<i);(++t)>>=1;
		fadd(ans,1LL*fib[i]*t%M);
	}
	return ans;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		read(n);
		printf("%d\n",f(n));
	}
	return 0;
}