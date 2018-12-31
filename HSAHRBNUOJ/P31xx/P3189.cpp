#include <cstdio>
#include <cstring>
#define MAXL 20000
using namespace std;

int t, cnt, pos, cas;
double ans;
double modular_wei[128];
char c;
char fomular[MAXL];

double deal_with_one()
{
	double weight = modular_wei[fomular[pos]];
	int num = 0;
	pos++;
	while (fomular[pos] >= '0' && fomular[pos] <= '9' && pos <= cnt)
	{
		num = num * 10 + fomular[pos] - '0';
		pos++;
	}
	if (!num) num++;
	return weight * double(num);
}

int main()
{
	//freopen("chemistry.in","r",stdin);freopen("chemistry.out","w",stdout);
	modular_wei['C'] = 12.01;
	modular_wei['H'] = 1.007;
	modular_wei['N'] = 14.006;
	modular_wei['O'] = 15.999;
	modular_wei['S'] = 32.06;
	scanf("%d", &t);
	getchar();
	while (t--)
	{
		printf("#Case %d:", ++cas);
		pos = 1;
		ans = 0.0;
		cnt = 0;
		/*  while (true)
		    {
			c=getchar();
			if (c=='\n') break;
			fomular[++cnt]=c;
		    }*/
		scanf("%s", fomular + 1);
		cnt = strlen(fomular + 1);
		while (pos <= cnt)
		{
			if (fomular[pos] >= 'A' && fomular[pos] <= 'Z')
				ans += deal_with_one();
			else if (fomular[pos] == '[')
			{
				double res1 = 0.0;
				pos++;
				int num = 0;
				while (fomular[pos] != ']')
				{
					if (fomular[pos] >= 'A' && fomular[pos] <= 'Z')
						res1 += deal_with_one();
					else if (fomular[pos] == '(')
					{
						pos++;
						double res2 = 0;
						while (fomular[pos] != ')')
							res2 += deal_with_one();
						pos++;
						int num1 = 0;
						while (fomular[pos] >= '0' && fomular[pos] <= '9')
						{
							num1 = num1 * 10 + fomular[pos] - '0';
							pos++;
						}
						res2 = res2 * double(num1);
						res1 += res2;
					}
				}
				pos++;
				while (fomular[pos] >= '0' && fomular[pos] <= '9')
				{
					num = num * 10 + fomular[pos] - '0';
					pos++;
				}
				ans += res1 * double(num);
			}
			else
			{
				double res3 = 0;
				int num2 = 0;
				while (fomular[pos] != ')')
					res3 += deal_with_one();
				pos++;
				int num1 = 0;
				while (fomular[pos] >= '0' && fomular[pos] <= '9')
				{
					num2 = num2 * 10 + fomular[pos] - '0';
					pos++;
				}
				ans += res3 * double(num2);
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
