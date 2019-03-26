#include <iostream>
using namespace std;

const int mod = 163577857, G = 23, MAXN = 1 << 20;
 
int gpow[30], invgpow[30];
int fact[MAXN], invfact[MAXN];
int inv[MAXN];
 
int raise(int number, int exponent) {
    int answer = 1;
    while (exponent) {
        if (exponent & 1) {
            answer = (long long)answer * number % mod;
        }
        number = (long long)number * number % mod;
        exponent >>= 1;
    }
    return answer;
}
 
void init() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (long long)fact[i - 1] * i % mod;
    }
    invfact[MAXN - 1] = raise(fact[MAXN - 1], mod - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        invfact[i] = (long long)invfact[i + 1] * (i + 1) % mod;
    }
    inv[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;
    }
 
    int where = (mod - 1) / 2, invg = raise(G, mod - 2);
    int idx = 0;
    while (where % 2 == 0) {
        idx++;
        gpow[idx] = raise(G, where);
        invgpow[idx] = raise(invg, where);
        where /= 2;
    }
}
 
void ntt(int *a, int n, int sign) {
    for (int i = n >> 1, j = 1; j < n; j++) {
        if (i < j) swap(a[i], a[j]);
        int k = n >> 1;
        while (k & i) {
            i ^= k;
            k >>= 1;
        }
        i ^= k;
    }
    for (int l = 2, idx = 1; l <= n; l <<= 1, idx++) {
        int omega = (sign == 1) ? gpow[idx] : invgpow[idx];
        for (int i = 0; i < n; i += l) {
            int value = 1;
            for (int j = i; j < i + (l>>1); j++) {
                int u = a[j], v = (long long)a[j + (l>>1)] * value % mod;
                a[j] = (u + v); a[j] = (a[j] >= mod) ? a[j] - mod : a[j];
                a[j + (l>>1)] = (u - v); a[j + (l>>1)] = (a[j + (l>>1)] < 0) ? a[j + (l>>1)] + mod : a[j + (l>>1)];
                value = (long long)value * omega % mod;
            }
        }
    }
    if (sign == -1) {
        const int x = raise(n, mod - 2);
        for (int i = 0; i < n; i++) {
            a[i] = (long long)a[i] * x % mod;
        }
    }
}
 
void multiply(int* a, int na, int* b, int nb) {
    na++; nb++;
    int n = 1; while (n < na + nb - 1) n <<= 1;
    for (int i = na; i < n; i++) {
        a[i] = 0;
    }
    for (int i = nb; i < n; i++) {
        b[i] = 0;
    }
 
    ntt(a, n, +1); ntt(b, n, +1);
    for (int i = 0; i < n; i++) {
        a[i] = (long long)a[i] * b[i] % mod;
    }
    ntt(a, n, -1);
    for (int i = na + nb - 1; i < n; i++) {
        a[i] = 0;
    }
}
 
int stirling[MAXN], shstr[MAXN];
int aux[MAXN];
 
void shiftStirling(int n) {
    for (int i = 0; i <= n; i++) {
        shstr[i] = (long long)fact[i] * stirling[i] % mod;
    }
    for (int i = 0, val = 1; i <= n; i++, val = (long long)val * n % mod) {
        aux[n - i] = (long long)val * invfact[i] % mod;
    }
    multiply(shstr, n, aux, n);
    for (int i = 0; i <= n; i++) {
        shstr[i] = (long long)shstr[i + n] * invfact[i] % mod;
    }
}
 
void compute(int n) {
    if (n == 1) {
        stirling[0] = 1;
        stirling[1] = 1;
        return;
    }
 
    compute(n >> 1);
    shiftStirling(n >> 1);
    if (n & 1) {
        for (int i = 0; i <= (n >> 1) + 1; i++) aux[i] = 0;
        for (int i = 0; i <= (n >> 1); i++) {
            aux[i] = (aux[i] + (long long)shstr[i] * n) % mod;
            aux[i+1] = (aux[i+1] + shstr[i]);
            aux[i+1] = (aux[i+1] >= mod) ? aux[i+1] - mod : aux[i+1];
        }
        for (int i = 0; i <= (n >> 1) + 1; i++) {
            shstr[i] = aux[i];
        }
    }
 
    multiply(stirling, n >> 1, shstr, (n + 1) >> 1);
}
 
int main() {
    init();
    
    int numtests; scanf("%d", &numtests);
    for (int tc = 0; tc < numtests; tc++) {
        int n, k; scanf("%d%d", &n, &k);
        compute(n);

        int answer = 0, binomial = 1;
        for (int i = 0; i < k; i++) {
            answer = (answer + (long long)stirling[n - i - 1] * binomial) % mod;
            binomial = (long long)binomial * (k - i - 1) % mod;
            binomial = (long long)binomial * inv[i + 1] % mod;
        }
        printf("%d\n", answer);
    }
 
    return 0;
}
