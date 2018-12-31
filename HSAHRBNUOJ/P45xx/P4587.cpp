#include <cstdio>
#include <cstring>
#define MAXN 1010
using namespace std;

struct program
{
	int x, cpl;
	program() {}
	program(int _, int __): x(_), cpl(__) {}
};

program sta[MAXN];
int n, T, lx, ly, a, b, top, zans, ans, cn;
char tar[15], name[15], x[15], y[15], opt[15];
bool CE, var[26];

inline int max(int &a, int b)
{
	if (a < b) a = b;
}

int main()
{
	//freopen("complexity.in","r",stdin);freopen("complexity.txt","w",stdout);
	scanf("%d", &T);
	while (T--)
	{
		CE = false;
		top = ans = zans = 0;
		memset(var, false, sizeof var);
		scanf("%d%s", &n, tar);
		while (n--)
		{
			scanf("%s", opt);
			if (opt[0] == 'F')
			{
				scanf("%s%s%s", name, x, y);
				cn = name[0] - 'a';
				if (CE) continue;
				if (var[cn])
				{
					CE = true;
					continue;
				}
				var[cn] = true;
				ans = sta[top++].cpl;
				if (x[0] == 'n')
				{
					if (y[0] == 'n') sta[top] = program(cn, ans);
					else sta[top] = program(cn, -1);
				}
				else
				{
					if (y[0] == 'n')
					{
						if (!~ans) sta[top] = program(cn, -1);
						else sta[top] = program(cn, ++ans);
						max(zans, ans);
					}
					else
					{
						lx = strlen(x);
						ly = strlen(y);
						a = b = 0;
						for (int i = 0; i < lx; i++) a = a * 10 + x[i] - '0';
						for (int i = 0; i < ly; i++) b = b * 10 + y[i] - '0';
						if (a <= b) sta[top] = program(cn, ans);
						else sta[top] = program(cn, -1);
					}
				}
			}
			else
			{
				if (CE) continue;
				if (top) var[sta[top--].x] = false;
				else CE = true;
			}
		}
		if (top || CE) puts("ERR");
		else
		{
			if (tar[2] == '1')
			{
				if (zans == 0) puts("Yes");
				else puts("No");
			}
			else
			{
				a = 0;
				for (int i = 4; tar[i] >= '0' && tar[i] <= '9'; i++) a = a * 10 + tar[i] - '0';
				if (a == zans) puts("Yes");
				else puts("No");
			}
		}
	}
	return 0;
}
