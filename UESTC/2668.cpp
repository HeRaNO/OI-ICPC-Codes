// By rockdu
#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL n;

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

int main() {
	srand(time(0));
	int t;
	LL n;
	cin >> t;
	while(t--) {
		LL res = 1;
		cin >> n;
		auto ans = Pollard_Rho::DCOMP(n);
		for(auto i : ans)
			if((i.first & 3) == 1)
				res *= (i.second << 1 | 1);
		printf("%lld\n", res << 2);
	}
	return 0;
}
