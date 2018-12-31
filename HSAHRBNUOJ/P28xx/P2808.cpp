#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#define MAXN 1010
#define MAX_L 200
using namespace std;
struct link
{
	int to;
	int nxt;
};
class bign
{
public:
	int len, s[MAX_L];
	bign();
	bign(const char *);
	bign(int);
	bool sign;
	bign operator=(const char *);
	bign operator=(int);
	bign operator=(const string);
	bool operator>(const bign &) const;
	bool operator>=(const bign &) const;
	bool operator<(const bign &) const;
	bool operator<=(const bign &) const;
	bool operator==(const bign &) const;
	bool operator!=(const bign &) const;
	bign operator+(const bign &) const;
	bign operator++();
	bign operator++(int);
	bign operator+=(const bign &);
	bign operator-(const bign &) const;
	bign operator--();
	bign operator--(int);
	bign operator-=(const bign &);
	bign operator*(const bign &)const;
	bign operator*(const int num)const;
	bign operator*=(const bign &);
	void clean();
};
#define max(a,b) a>b ? a : b
#define min(a,b) a<b ? a : b

bign::bign()
{
	memset(s, 0, sizeof(s));
	len = 1;
	sign = 1;
}

bign::bign(const char *num)
{
	*this = num;
}

bign::bign(int num)
{
	*this = num;
}

bign bign::operator=(const char *num)
{
	memset(s, 0, sizeof(s));
	char a[MAX_L] = "";
	if (num[0] != '-')
		strcpy(a, num);
	else
	{
		int len = strlen(num);
		for (int i = 1; i < len; i++)
			a[i - 1] = num[i];
	}
	sign = !(num[0] == '-');
	len = strlen(a);
	for (int i = 0; i < len; i++)
		s[i] = a[len - i - 1] - 48;
	return *this;
}

bign bign::operator=(int num)
{
	if (num < 0)
		sign = 0, num = -num;
	else
		sign = 1;
	char temp[MAX_L];
	sprintf(temp, "%d", num);
	*this = temp;
	return *this;
}

bign bign::operator=(const string num)
{
	const char *tmp;
	tmp = num.c_str();
	*this = tmp;
	return *this;
}

bool bign::operator<(const bign &num) const
{
	if (sign ^ num.sign)
		return num.sign;
	if (len != num.len)
		return len < num.len;
	for (int i = len - 1; i >= 0; i--)
		if (s[i] != num.s[i])
			return sign ? (s[i] < num.s[i]) : (!(s[i] < num.s[i]));
	return !sign;
}

bool bign::operator>(const bign &num)const
{
	return num < *this;
}

bool bign::operator<=(const bign &num)const
{
	return !(*this > num);
}

bool bign::operator>=(const bign &num)const
{
	return !(*this < num);
}

bool bign::operator!=(const bign &num)const
{
	return *this > num || *this < num;
}

bool bign::operator==(const bign &num)const
{
	return !(num != *this);
}

bign bign::operator+(const bign &num) const
{
	if (sign ^ num.sign)
	{
		bign tmp = sign ? num : *this;
		tmp.sign = 1;
		return sign ? *this - tmp : num - tmp;
	}
	bign result;
	result.len = 0;
	int temp = 0;
	for (int i = 0; temp || i < (max(len, num.len)); i++)
	{
		int t = s[i] + num.s[i] + temp;
		result.s[result.len++] = t % 10;
		temp = t / 10;
	}
	result.sign = sign;
	return result;
}

bign bign::operator++()
{
	*this = *this + 1;
	return *this;
}

bign bign::operator++(int)
{
	bign old = *this;
	++(*this);
	return old;
}

bign bign::operator+=(const bign &num)
{
	*this = *this + num;
	return *this;
}

bign bign::operator-(const bign &num) const
{
	bign b = num, a = *this;
	if (!num.sign && !sign)
	{
		b.sign = 1;
		a.sign = 1;
		return b - a;
	}
	if (!b.sign)
	{
		b.sign = 1;
		return a + b;
	}
	if (!a.sign)
	{
		a.sign = 1;
		b = bign(0) - (a + b);
		return b;
	}
	if (a < b)
	{
		bign c = (b - a);
		c.sign = false;
		return c;
	}
	bign result;
	result.len = 0;
	for (int i = 0, g = 0; i < a.len; i++)
	{
		int x = a.s[i] - g;
		if (i < b.len) x -= b.s[i];
		if (x >= 0) g = 0;
		else
		{
			g = 1;
			x += 10;
		}
		result.s[result.len++] = x;
	}
	result.clean();
	return result;
}

bign bign::operator * (const bign &num)const
{
	bign result;
	result.len = len + num.len;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < num.len; j++)
			result.s[i + j] += s[i] * num.s[j];
	for (int i = 0; i < result.len; i++)
	{
		result.s[i + 1] += result.s[i] / 10;
		result.s[i] %= 10;
	}
	result.clean();
	result.sign = !(sign ^ num.sign);
	return result;
}

bign bign::operator*(const int num)const
{
	bign x = num;
	bign z = *this;
	return x * z;
}
bign bign::operator*=(const bign &num)
{
	*this = *this * num;
	return *this;
}

void bign::clean()
{
	if (len == 0) len++;
	while (len > 1 && s[len - 1] == '\0')
		len--;
}

link e[2 * MAXN];
int n, cnt, u, v, x;
int edge_num[MAXN];
bign dp1[MAXN][2], dp2[MAXN][2];
int son[MAXN], siz;
bign l, suml, sumr[MAXN], r[MAXN];

inline bign mymax(bign a, bign b)
{
	return a > b ? a : b;
}

void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, edge_num[u]
	};
	edge_num[u] = cnt++;
	e[cnt] = (link)
	{
		u, edge_num[v]
	};
	edge_num[v] = cnt++;
}

void TreeDP(int node, int father)
{
	bign mx, tmp;
	dp2[node][0] = 1;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
	{
		if (e[i].to == father) continue;
		TreeDP(e[i].to, node);
		mx = mymax(dp1[e[i].to][0], dp1[e[i].to][1]);
		tmp = 0;
		if (dp1[e[i].to][0] == mx) tmp += dp2[e[i].to][0];
		if (dp1[e[i].to][1] == mx) tmp += dp2[e[i].to][1];
		dp2[node][0] = dp2[node][0] * tmp;
		dp1[node][0] += mx;
	}
	siz = 0;
	for (int i = edge_num[node]; ~i; i = e[i].nxt)
		if (e[i].to != father) son[++siz] = e[i].to;
	l = 0;
	suml = 1;
	sumr[siz + 1] = 1;
	r[siz + 1] = 0;
	for (int i = siz; i; i--)
	{
		mx = mymax(dp1[son[i]][0], dp1[son[i]][1]);
		tmp = 0;
		if (mx == dp1[son[i]][0]) tmp += dp2[son[i]][0];
		if (mx == dp1[son[i]][1]) tmp += dp2[son[i]][1];
		r[i] = r[i + 1] + mx;
		sumr[i] = sumr[i + 1] * tmp;
	}
	dp1[node][1] = INT_MIN;
	for (int i = 1; i <= siz; i++)
	{
		tmp = l + dp1[son[i]][0] + r[i + 1] + 1;
		if (tmp > dp1[node][1])
		{
			dp1[node][1] = tmp;
			dp2[node][1] = (dp2[son[i]][0] * (suml * sumr[i + 1]));
		}
		else if (tmp == dp1[node][1])
			dp2[node][1] = (dp2[node][1] + (dp2[son[i]][0] * (suml * sumr[i + 1])));
		mx = mymax(dp1[son[i]][0], dp1[son[i]][1]);
		tmp = 0;
		if (mx == dp1[son[i]][0]) tmp += dp2[son[i]][0];
		if (mx == dp1[son[i]][1]) tmp += dp2[son[i]][1];
		suml = suml * tmp;
		l += mx;
	}
	return ;
}

int main()
{
	cnt = 0;
	memset(edge_num, -1, sizeof edge_num);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &x, &u);
		for (int j = 1; j <= u; j++)
		{
			scanf("%d", &v);
			add(x, v);
		}
	}
	TreeDP(1, 1);
	bign ans1 = mymax(dp1[1][0], dp1[1][1]);
	bign ans2 = 0;
	if (ans1 == dp1[1][0]) ans2 += dp2[1][0];
	if (ans1 == dp1[1][1]) ans2 += dp2[1][1];
	for (int i = ans1.len - 1; ~i; i--) printf("%d", ans1.s[i]);
	puts("");
	for (int i = ans2.len - 1; ~i; i--) printf("%d", ans2.s[i]);
	puts("");
	return 0;
}
