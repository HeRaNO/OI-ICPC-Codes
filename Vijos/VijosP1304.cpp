#include<iostream>
#include<cstring>
using namespace std;
struct bign
{
	int len, num[1001];
	bign()
	{
		len = 0;
		memset(num, 0, sizeof(num));
	}
};
int getnum(char ch)
{
	if (ch >= '0' && ch <= '9')return (int)ch - '0';
	if (ch >= 'A' && ch <= 'Z')return (int)ch - 'A' + 10;
}
bign pplus(bign a, bign b, int k)
{
	int j = 0;
	bign c;
	for (int i = 0; j || i < max(a.len, b.len); i++)
	{
		if (i < a.len)j += a.num[i];
		if (i < b.len)j += b.num[i];
		c.num[c.len++] = j % k;
		j /= k;
	}
	return c;
}
bign reverse(bign a)
{
	int i = a.len - 1, j;
	bign b;
	for (j = 0; j <= a.len - 1; j++)
		if (a.num[j] != 0)break;
	for (i; i >= j; i--)
		b.num[b.len++] = a.num[i];
	return b;
}
bool dengyu(bign a, bign b)
{
	if (a.len != b.len)return false;
	for (int i = 0; i <= a.len - 1; i++)
		if (a.num[i] != b.num[i])return false;
	return true;
}
string m;
int n, step = 0;
bign sum;
int main()
{
	cin >> n >> m;
	for (int i = m.length() - 1; i >= 0; i--)
		sum.num[sum.len++] = getnum(m[i]);
	while (!dengyu(sum, reverse(sum)))
	{
		sum = pplus(sum, reverse(sum), n);
		if (++step >= 30)
		{
			cout << "Impossible!";
			return 0;
		}
	}
	cout << "STEP=" << step;
	return 0;
}