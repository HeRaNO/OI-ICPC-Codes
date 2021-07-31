#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int T,a,p,m,x,B,C,__y1,__y2,inv2;
LL l,r,ans,R,Rrt;

inline void Tassert(bool x)
{
	//if (!x) while (1);
	return ;
}

namespace NT {
	LL gcd(LL a, LL b) {
		return b ? gcd(b, a % b) : a;
	}
	LL mul(LL a, LL b, LL m) {
		LL s = a * b - (LL)((long double)a * b / m + 0.5) * m;
		return s < 0 ? s + m : s;
	}
	LL fpow(LL x, LL a, LL m) {
		LL ans = 1;
		while(a) {
			if(a & 1) ans = mul(ans, x, m);
			x = mul(x, x, m), a >>= 1;
		}
		return ans;
	}
}

namespace Miller_Rabin {
	using namespace NT;
	LL p[15] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	int detect(LL n, LL a) {
		if(n == a) return 1;
		if(a % n == 0) return 1;
		LL now = n - 1, lst = 1;
		if(fpow(a, now, n) != 1) 
			return 0;
		while(!(now & 1)) {
			now /= 2;
			LL p = fpow(a, now, n);
			if(lst == 1 && p != 1 && p != n - 1)
				return 0;
			lst = p;
		}
		return 1;
	}
	
	LL MR(LL n) {
		if(n < 2) return 0;
		for(int i = 0; i < 7; ++i) {
			if(!detect(n, p[i])) 
				return 0;
		}
		return 1;
	}
}

namespace Pollard_Rho {
	using namespace NT;
	using namespace Miller_Rabin;
	LL f(LL x, LL C, LL p) {
		return (mul(x, x, p) + C) % p;
	}
	LL Rand() {return (rand() << 15) + rand();}
	LL Randll() {return (Rand() << 31) + Rand();}
	
	LL PR(LL n) {
		if(n == 4) return 2;
		if(MR(n)) return n;
		while(1) {
			LL C = Randll() % (n - 1) + 1;
			LL s = 0, t = 0;
			LL acc = 1;
			do {
				for(int i = 1; i <= 128; ++i) {
					t = f(f(t, C, n), C, n);
					s = f(s, C, n);
					LL tmp = mul(acc, abs(t - s), n);
					if(s == t || tmp == 0)
						break;
					acc = tmp;
				}
				LL d = gcd(n, acc);
				if(d > 1) return d;
			} while(s != t);
		}
	}
	
	typedef pair<LL, int > pii;
	vector<pii > DCOMP(LL n) {
		vector<pii > ret;
		while(n != 1) {
			LL p = PR(n);
			while(!MR(p)) 
				p = PR(p);
			int c = 0;
			while(n % p == 0) n /= p, ++c;
			ret.push_back(make_pair(p, c));
		}
		return ret;
	}
}

struct Matrix
{
	int m[2][2];
	Matrix(){
		m[0][0]=m[1][1]=1;
		m[1][0]=m[0][1]=0;
	}
	Matrix operator * (const Matrix &a)const{
		Matrix res;
		res.m[0][0]=(1LL*m[0][0]*a.m[0][0]+1LL*m[0][1]*a.m[1][0])%p;
		res.m[0][1]=(1LL*m[0][0]*a.m[0][1]+1LL*m[0][1]*a.m[1][1])%p;
		res.m[1][0]=(1LL*m[1][0]*a.m[0][0]+1LL*m[1][1]*a.m[1][0])%p;
		res.m[1][1]=(1LL*m[1][0]*a.m[0][1]+1LL*m[1][1]*a.m[1][1])%p;
		return res;
	}
	long long hashVal(){
		return (long long)m[0][0]<<30|m[0][1];
	}
}I;

int fpow(int a,int b)
{
	int r=1;
	for (;b;b>>=1,a=1LL*a*a%p) if (b&1) r=1LL*r*a%p;
	return r;
}

Matrix fpow(Matrix a,long long b)
{
	Matrix r;
	for (;b;b>>=1,a=a*a) if (b&1) r=r*a;
	return r;
}

int msqrt(int n,int p)
{
	if (!n) return 0;
	int q=p-1,s=0,z=2;q>>=(s=__builtin_ctzll(q));
	if (s==1) return fpow(n,(p+1)>>2);
	while (fpow(z,(p-1)>>1)==1) ++z;
	int c=fpow(z,q),t=fpow(n,q);
	int r=fpow(n,(q+1)>>1),m=s;
	while (t%p!=1)
	{
		int i=1;
		while (fpow(t,1<<i)!=1) ++i;
		long long b=fpow(c,1<<(m-i-1));
		r=1LL*r*b%p;c=1LL*b*b%p;t=1LL*t*c%p;m=i;
	}
	return min(r,p-r);
}

bool qce(int b,int c,int& x1,int& x2)
{
	int d=((1LL*b*b-1LL*4*c)%p+p)%p;
	if (fpow(d,(p-1)>>1)==p-1) return false;
	d=msqrt(d,p);
	x1=1LL*(p-b+d)*inv2%p;x2=1LL*(2*p-b-d)*inv2%p;
	return true;
}

unordered_map <long long,int> mp;
Matrix t,BASE;

void BSGS_prepare(int m)
{
	Matrix y;mp.clear();
	for (int i=0;i<m;i++,y=y*BASE)
		if (!mp.count(y.hashVal()))
			mp.insert({y.hashVal(),i});
	t.m[0][0]=0;t.m[0][1]=t.m[1][0]=1;t.m[1][1]=p-a%p;
	t=fpow(t,m);
	return ;
}

long long BSGS(Matrix b,int m)
{
	for (int i=0;i<m;i++,b=b*t)
		if (mp.count(b.hashVal()))
			return 1LL*i*m+mp[b.hashVal()];
	return -1;
}

inline long long f(long long x,long long t)
{
	return x/R+(t<=x%R);
}

inline void Solve(int y)
{
	Matrix m;
	m.m[0][0]=B+y;if (m.m[0][0]>p) m.m[0][0]-=p;
	m.m[0][1]=m.m[1][0]=x;
	m.m[1][1]=y;
	long long t=BSGS(m,Rrt);
	if (!~t) return ;
	t%=R;
	ans+=f(r,t)-f(l-1,t);
	return ;
}

inline int Legendre(long long x,int p)
{
	return fpow(x%p,(p-1)>>1);
}

inline bool JudgePeriod(long long p)
{
	return fpow(BASE,p).hashVal()==I.hashVal();
}

inline long long CalcPeriod(long long x)
{
	auto fact=Pollard_Rho::DCOMP(x);
	vector <long long> f;
	f.push_back(1);int lst=1;long long lstpri=1,now;
	for (auto pf:fact)
	{
		now=1;lst=f.size();
		for (int i=1;i<=pf.second;i++)
		{
			now*=pf.first;
			for (int j=0;j<lst;j++) f.push_back(now*f[j]);
		}
	}
	for (auto p:f)
		if (p!=1&&JudgePeriod(p))
			return p;
	Tassert(false);
	return -1;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %d %d %lld %lld",&a,&p,&x,&l,&r);inv2=(p+1)>>1;
		BASE.m[0][0]=a;BASE.m[0][1]=BASE.m[1][0]=1;BASE.m[1][1]=0;
		if ((1LL*a*a+4)%p==0) R=(long long)p<<2;
		else
		{
			if (Legendre(1LL*a*a+4,p)==1)
				R=CalcPeriod(p-1);
			else
				R=CalcPeriod(1LL*p*p-1);
		}
		Rrt=ceil(sqrt(R));
		BSGS_prepare(Rrt);
		B=1LL*a*x%p;C=(1LL*x*x+1)%p;C=p-C;
		int slot0=-1,slot1=-1,slot2=-1;
		if (qce(B,C,__y1,__y2))
		{
			Solve(__y1);
			slot0=__y1;
			if (__y2!=__y1)
			{
				Solve(__y2);
				slot1=__y2;
			}
		}
		C+=2;if (C>=p) C-=p;
		if (qce(B,C,__y1,__y2))
		{
			if (__y1!=slot0&&__y1!=slot1)
			{
				Solve(__y1);
				slot2=__y1;
			}
			if (__y2!=slot0&&__y2!=slot1&&__y1!=__y2)
				Solve(__y2);
		}
		printf("%lld\n",ans);ans=0;
	}
	return 0;
}
