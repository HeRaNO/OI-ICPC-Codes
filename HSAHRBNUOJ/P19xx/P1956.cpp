#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct strr
{
	char st;
	int yuanpos;
};

const int MAXN = 200100;
char flag, yuanstr[MAXN];
strr str[MAXN];
char s[2 * MAXN];
int i, k;
int p[2 * MAXN];
int len;
int tmp, tmp2;
int id, maxlen;
int maxpos;
int beginpo, endpo, mid;

int main()
{
	//freopen("a.txt","w",stdout);
	while (scanf("%c", &flag) != EOF)
		yuanstr[len++] = flag;
	for (i = 0; i <= len; i++)
	{
		tmp = yuanstr[i];
		if ((tmp >= 65 && tmp <= 90) || (tmp >= 97 && tmp <= 122))
		{
			tmp2 = k++;
			str[tmp2].st = yuanstr[i];
			str[tmp2].yuanpos = i;
		}
	}
	for (i = 0; i <= k; i++)
	{
		if (str[i].st >= 97 && str[i].st <= 122)
			str[i].st -= 32;
		s[i] = str[i].st;
	}
	for (i = k; i >= 0; --i)
	{
		s[i + i + 2] = s[i];
		s[i + i + 1] = '#';
	}
	s[0] = '*';
	for (i = 2 * k; i >= 2; i--)
	{
		if (p[id] + id > i)p[i] = min(p[2 * id - i], p[id] + id - i);
		else p[i] = 1;
		while (s[i - p[i]] == s[i + p[i]]) ++p[i];
		if (id + p[id] < i + p[i]) id = i;
		if (maxlen < p[i])
		{
			maxlen = p[i];
			maxpos = i;
		}
		if (maxlen == p[i])
			maxpos = i;
	}
	maxlen--;
	cout << maxlen << endl;
	if (s[maxpos] == '#') //回文串长为偶数
	{
		maxpos = (maxpos + 1) / 2;
		tmp = maxlen / 2;
		beginpo = str[maxpos - tmp - 1].yuanpos;
		endpo = str[maxpos + tmp - 2].yuanpos;
		for (i = beginpo; i <= endpo; i++)
			cout << yuanstr[i];
	}
	else  //回文串长度为奇数
	{
		maxpos /= 2;
		tmp = (maxlen - 1) / 2;
		beginpo = str[maxpos - tmp - 1].yuanpos;
		endpo = str[maxpos + tmp - 1].yuanpos;
		for (i = beginpo; i <= endpo; i++)
			cout << yuanstr[i];
	}
	cout << endl;
	return 0;
}
