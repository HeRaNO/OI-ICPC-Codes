#include <string>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define MAX_L 1000
#define MAXN 83
using namespace std;

class bign
{
public:
	int len, s[MAX_L];
	bign();
	bign operator=(int num)
	{
		int wei = 0;
		while (num)
		{
			s[wei++] = num % 10;
			num /= 10;
		}
		len = wei;
	}
	bool operator>(const bign &) const;
	bool operator<(const bign &) const;
	bign operator+(const bign &) const;
	bign operator*(const bign &)const;
	bign operator*(const int num)const;
	void clean();
	~bign();
};
#define max(a,b) a>b ? a : b
#define min(a,b) a<b ? a : b

bign::bign()
{
	memset(s, 0, sizeof(s));
	len = 1;
}

bool bign::operator<(const bign &num)const
{
	if (len != num.len)
		return len < num.len;
	for (int i = len - 1; i >= 0; i--)
		if (s[i] != num.s[i])
			return s[i] < num.s[i];
	return true;
}

bool bign::operator>(const bign &num)const
{
	return num < *this;
}

bign bign::operator+(const bign &num)const
{
	bign result;
	result.len = 0;
	int temp = 0;
	for (int i = 0; temp || i < (max(len, num.len)); i++)
	{
		int t = s[i] + num.s[i] + temp;
		result.s[result.len++] = t % 10;
		temp = t / 10;
	}
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
	return result;
}

bign bign::operator*(const int num)const
{
	bign x;
	x = num;
	bign z = *this;
	return x * z;
}

void bign::clean()
{
	if (len == 0) len++;
	while (len > 1 && s[len - 1] == '\0')
		len--;
}

bign::~bign()
{
}

bign dp[MAXN][MAXN];
bign two[MAXN];
bign ans, best;
bign yi, er, ling;
bign a[MAXN][MAXN];
int n, m, x;

bign mymax(bign a, bign b)
{
	return a > b ? a : b;
}

int main()
{
	yi = 1;
	er = 2;
	ling = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &x);
			a[i][j] = x;
		}
	two[0] = yi;
	for (int i = 1; i <= m; i++)
		two[i] = two[i - 1] * er;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
			for (int l = 0; l <= j; l++)
			{
				int r = j - l;
				dp[l][r] = ling;
				if (l > 0) dp[l][r] = dp[l - 1][r] + two[j] * a[i][l - 1];
				if (r > 0) dp[l][r] = mymax(dp[l][r], dp[l][r - 1] + two[j] * a[i][m - r]);
			}
		best = ling;
		for (int j = 0; j <= m; j++) best = mymax(best, dp[j][m - j]);
		ans = ans + best;
	}
	for (int i = ans.len - 1; ~i; i--) putchar(ans.s[i] + '0');
	putchar('\n');
	return 0;
}