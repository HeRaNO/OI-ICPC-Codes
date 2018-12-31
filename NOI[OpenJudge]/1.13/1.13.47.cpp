//Code By HeRaNO
#include <string>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define MAX_L 10010 //最大长度，可以修改
using namespace std;

class bign
{
public:
	int len, s[MAX_L];//数的长度，记录数组
	//构造函数
	bign();
	bign(const char *);
	bign(int);
	bool sign;//符号 1正数 0负数
	string toStr() const;//转化为字符串，主要是便于输出
	friend istream &operator>>(istream &, bign &); //重载输入流
	friend ostream &operator<<(ostream &, bign &); //重载输出流
	//重载复制
	bign operator=(const char *);
	bign operator=(int);
	bign operator=(const string);
	//重载各种比较
	bool operator>(const bign &) const;
	bool operator>=(const bign &) const;
	bool operator<(const bign &) const;
	bool operator<=(const bign &) const;
	bool operator==(const bign &) const;
	bool operator!=(const bign &) const;
	//重载四则运算
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
	bign operator/(const bign &)const;
	bign operator/=(const bign &);
	//四则运算的衍生运算
	bign operator%(const bign &)const; //取模（余数）
	bign factorial()const;//阶乘
	bign Sqrt()const;//整数开根（向下取整）
	bign pow(const bign &)const; //次方
	//一些乱乱的函数
	void clean();
	~bign();
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

string bign::toStr() const
{
	string res;
	res = "";
	for (int i = 0; i < len; i++)
		res = (char)(s[i] + '0') + res;
	if (res == "")
		res = "0";
	if (!sign && res != "0")
		res = "-" + res;
	return res;
}

istream &operator>>(istream &in, bign &num)
{
	string str;
	in >> str;
	num = str;
	return in;
}

ostream &operator<<(ostream &out, bign &num)
{
	out << num.toStr();
	return out;
}

bign bign::operator=(const char *num)
{
	memset(s, 0, sizeof(s));
	char a[MAX_L] = "";
	if (num[0] != '-')
		strcpy(a, num);
	else
		for (int i = 1; i < strlen(num); i++)
			a[i - 1] = num[i];
	sign = !(num[0] == '-');
	len = strlen(a);
	for (int i = 0; i < strlen(a); i++)
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

bign bign::operator /(const bign &num)const
{
	bign ans;
	ans.len = len - num.len + 1;
	if (ans.len < 0)
	{
		ans.len = 1;
		return ans;
	}
	bign divisor = *this, divid = num;
	divisor.sign = divid.sign = 1;
	int k = ans.len - 1;
	int j = len - 1;
	while (k >= 0)
	{
		while (divisor.s[j] == 0) j--;
		if (k > j) k = j;
		char z[MAX_L];
		memset(z, 0, sizeof(z));
		for (int i = j; i >= k; i--)
			z[j - i] = divisor.s[i] + '0';
		bign dividend = z;
		if (dividend < divid)
		{
			k--;
			continue;
		}
		int key = 0;
		while (divid * key <= dividend) key++;
		key--;
		ans.s[k] = key;
		bign temp = divid * key;
		for (int i = 0; i < k; i++)
			temp = temp * 10;
		divisor = divisor - temp;
		k--;
	}
	ans.clean();
	ans.sign = !(sign ^ num.sign);
	return ans;
}

bign bign::operator/=(const bign &num)
{
	*this = *this / num;
	return *this;
}

bign bign::operator%(const bign &num)const
{
	bign a = *this, b = num;
	a.sign = b.sign = 1;
	bign result, temp = a / b * b;
	result = a - temp;
	result.sign = sign;
	return result;
}

bign bign::pow(const bign &num)const
{
	bign result = 1;
	for (bign i = 0; i < num; i++)
		result = result * (*this);
	return result;
}

bign bign::factorial()const
{
	bign result = 1;
	for (bign i = 1; i <= *this; i++)
		result *= i;
	return result;
}

void bign::clean()
{
	if (len == 0) len++;
	while (len > 1 && s[len - 1] == '\0')
		len--;
}

bign bign::Sqrt()const
{
	if (*this < 0)return -1;
	if (*this <= 1)return *this;
	bign l = 0, r = *this, mid;
	while (r - l > 1)
	{
		mid = (l + r) / 2;
		if (mid * mid > *this)
			r = mid;
		else
			l = mid;
	}
	return l;
}

bign::~bign()
{
}

bign a, b, c;

int main()
{
	cin >> a;
	cin >> b;
	c = a / b;
	cout << c << endl;
	return 0;
}
