//这模拟，真恶心......
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
string name[11];
int in[11] = {0}, out[11] = {0};
int i, j, k;
int n;
int loc;
int giveout, givenum;
string nametmp, nametmp1;
int main()
{
	//freopen("a.txt","r",stdin);
	//freopen("ans.txt","w",stdout);
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin.clear();
		cin >> name[i];
	}
	for (i = 1; i <= n; i++)
	{
		cin.clear();
		cin >> nametmp;
		for (j = 1; j <= n; j++)
			if (nametmp == name[j])
			{
				loc = j;
				break;
			}
		cin >> giveout >> givenum;
		if (giveout != 0)
		{
			for (j = 1; j <= givenum; j++)
			{
				cin.clear();
				cin >> nametmp1;
				for (k = 1; k <= n; k++)
				{
					if (name[k] == nametmp1)
						in[k] += giveout / givenum;
				}
			}
			out[loc] += givenum * (giveout / givenum);
		}
	}
	for (i = 1; i <= n; i++)
	{
		cout << name[i] << " ";
		cout << in[i] - out[i] << endl;
	}
	return 0;
}