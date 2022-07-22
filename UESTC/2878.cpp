#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 lll;

ll exgcd(ll a, ll b, ll& u, ll& v) {
    ll d;
    if (b) d = exgcd(b, a % b, v, u), v -= (a / b) * u;
    else d = a, u = 1, v = 0;
    return d;
}

bool lce(ll& a, ll& b, ll& p) {
    ll x, k, d = exgcd(a, p, x, k);
    if (b % d == 0) {
        a = 1; p /= d;
        b = (((__int128)b / d * x) % p + p) % p;
    }
    return a == 1;
}

bool crt(ll& b1, ll& m1, ll b2, ll m2) {
    ll a = m1, b = ((b2 - b1) % m2 + m2) % m2, p = m2;
    if (!lce(a, b, p)) return false;
    else { b1 += b * m1; m1 *= p; return true;}
}

int p, w;

int add(int a, int b) { a += b; return a < p ? a : a - p; }
int sub(int a, int b) { a -= b; return a < 0 ? a + p : a; }
int mul(int a, int b) { return 1ll * a * b % p; }
int qpm(int a, ll b) {
    int r = 1;
    do if (b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}

struct c { int a, b; };
c add(c u, c v) { return { add(u.a, v.a), add(u.b, v.b) }; }
c sub(c u, c v) { return { sub(u.a, v.a), sub(u.b, v.b) }; }
c mul(c u, c v) { return { 
        add(mul(u.a, v.a), mul(w, mul(u.b, v.b))),
        add(mul(u.a, v.b), mul(u.b, v.a))
    };
}
c qpm(c u, ll b) {
    c r = { 1, 0 };
    do if (b & 1) r = mul(r, u);
    while (u = mul(u, u), b >>= 1);
    return r;
}
c inv(c u) {
    return qpm(u, 1ll * p * p - 2);
}

bool operator<(c u, c v) { return u.a == v.a ? u.b < v.b : u.a < v.a; }
bool operator==(c u, c v) { return u.a == v.a && u.b == v.b; }
bool operator!=(c u, c v) { return u.a != v.a || u.b != v.b; }

struct pf { int p, e; };
//  Factor p * p - 1
vector<pf> pfdp2_1() {
    map<int, int> m;
    int na[2] = { p - 1, p + 1 };
    for (int& n : na) {
        for (int i = 2; i * i <= n; ++i)
            for (; n % i == 0; n /= i)
                m[i]++;
        if (n != 1)
            m[n]++;
    }
    vector<pf> res;
    for (auto z : m)
        res.push_back({ z.first, z.second });
    return res;
}

c primitive_root(vector<pf>& res) {
    static mt19937_64 mt;
    uniform_int_distribution<int> ur(0, p - 1);
    bool fail = 1;
    c g;
    ll n = 1ll * p * p - 1;
    do {
        fail = 0;
        g = { ur(mt), ur(mt) };
        if (g.a == 0 && g.b == 0)
            fail = 1;
        for (pf z : res) {
            if (qpm(g, n / z.p) == c{ 1, 0 }) {
                fail = 1;
                break;
            }
        }
    } while (fail);
    return g;
}

struct bsgs_t {
    int n;
    int s;
    c g;
    map<c, int> m;

    bsgs_t(c g_, int n_) : n(n_), s(ceil(sqrt(n))), g(g_) {
        c a = { 1, 0 };
        for (int i = 0; i < s; ++i, a = mul(a, g))
            m[a] = i;
    }

    int query(c x) {
        c b = inv(qpm(g, s));
        for (int i = 0; i < s; ++i, x = mul(x, b)) {
            auto it = m.find(x);
            if (it != m.end())
                return it->second + i * s;
        }
        return -1;
    }
};

ll pohlig_hellman(const vector<pf>& ps, c g, c x) {
    ll n = 1ll * p * p - 1;

    ll b = 0, m = 1;
    for (pf z : ps) {
        bsgs_t bsgs(qpm(g, n / z.p), z.p);

        ll q = 1;
        for (int i = 0; i < z.e; ++i) q *= z.p;

        c h = qpm(g, n / q), y = qpm(x, n / q);
        ll k = 0, w = 1;
        for (int i = 0; i < z.e; ++i) {
            q /= z.p;
            int r = bsgs.query(qpm(y, q));
            k += w * r;
            y = mul(y, inv(qpm(h, w * r)));
            w *= z.p;
        }
        assert(crt(b, m, k, w));
    }
    assert(m == n);
    return b;
}

int main(void) {
    int t; scanf("%d", &t);
    while (t--) {
        int a, b; ll k;
        scanf("%d %d %d %d %lld", &p, &a, &b, &w, &k);
        assert(qpm(w, (p - 1) / 2) == p - 1);
        if (a == 0 && b == 0)
            printf("1 0 0\n");
        else {
            vector<pf> ps = pfdp2_1();
            c g = primitive_root(ps), x = { a, b };
            ll r = pohlig_hellman(ps, g, x);
            assert(qpm(g, r) == x);
            ll z = 1ll * p * p - 1;
            ll kk = k, rr = r, zz = z;
            if (!lce(kk, rr, zz))
                printf("0\n");
            else {
                ll ans = z / zz;
                c h = qpm(g, rr);
                printf("%lld %d %d\n", ans, h.a, h.b);
                assert((qpm(h, k) == c{ a, b }));
            }
        }
    }

    return 0;
}