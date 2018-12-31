#include <cstdio>
#include <cstring>
#define MAX_L 100010
using namespace std;

class bign
{
public:
	int len, s[MAX_L];
	bign();
	bool sign;
	bign operator=(const char *);
	bool operator<(const bign &) const;
	bign operator+(const bign &) const;
	bign operator-(const bign &) const;
	void clean();
};

#define max(a,b) a>b ? a : b
#define min(a,b) a<b ? a : b
bign zero;

bign::bign()
{
	memset(s, 0, sizeof(s));
	len = 1;
	sign = 1;
}

bign bign::operator=(const char *num)
{
	memset(s, 0, sizeof(s));
	char a[MAX_L] = "";
	if (num[0] != '-') strcpy(a, num);
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
		b = zero - (a + b);
		return b;
	}
	if (a < b)
	{
		bign c = b - a;
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

void bign::clean()
{
	if (len == 0) len++;
	while (len > 1 && s[len - 1] == '\0')
		len--;
}

char a[MAX_L], b[MAX_L];
bign aa, bb, c;

int main()
{
	scanf("%s", a);
	scanf("%s", b);
	aa = a;
	bb = b;
	c = aa + bb;
	if (!c.sign) putchar('-');
	for (int i = c.len - 1; ~i; i--) printf("%d", c.s[i]);
	puts("");
	return 0;
}
