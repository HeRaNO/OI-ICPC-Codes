#include <cstdio>
#include <cstring>
#define MAXN 1000100
using namespace std;

struct mystruct
{
	char c;
	int pos;
};

mystruct sta[MAXN];
char in[MAXN];
bool cover[MAXN] = {false};
int n;
int sta_num;
int start, endd, maxx;

bool ok(char a, char b)
{
	if (a == '(') return b == ')';
	if (a == '[') return b == ']';
	else return false;
}

int main()
{
	gets(in);
	n = strlen(in);
	mystruct tmp;
	for (int i = 0; i < n; i++)
	{
		if (sta_num && ok(sta[sta_num - 1].c, in[i]))
		{
			cover[sta[sta_num - 1].pos] = true;
			cover[i] = true;
			sta_num--;
		}
		else
		{
			tmp.c = in[i];
			tmp.pos = i;
			sta[sta_num++] = tmp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!cover[i]) continue;
		int j;
		for (j = i; cover[j]; j++) ;
		if (maxx < j - i)
		{
			maxx = j - i;
			start = i;
			endd = j;
		}
		i = j;
	}
	for (int i = start; i < endd; i++)
		printf("%c", in[i]);
	puts("");
	return 0;
}
