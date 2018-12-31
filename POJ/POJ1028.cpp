#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 1100
using namespace std;

string bac[MAXN], forw[MAXN];
int topb, topf;
string nowpage, inpage, opt;

int main()
{
	//freopen("kami.in","r",stdin);freopen("kami.out","w",stdout);
	nowpage = "http://www.acm.org/";
	while (true)
	{
		cin >> opt;
		if (opt == "QUIT") break;
		else if (opt == "BACK")
		{
			if (!topb)
			{
				puts("Ignored");
				continue;
			}
			else
			{
				forw[++topf] = nowpage;
				nowpage = bac[topb--];
			}
		}
		else if (opt == "FORWARD")
		{
			if (!topf)
			{
				puts("Ignored");
				continue;
			}
			else
			{
				bac[++topb] = nowpage;
				nowpage = forw[topf--];
			}
		}
		else
		{
			cin >> inpage;
			bac[++topb] = nowpage;
			nowpage = inpage;
			topf = 0;
		}
		cout << nowpage << endl;
	}
	return 0;
}
