//Code By HeRaNO
#include <cstring>
#include <iostream>
#define MAXN 210
using namespace std;

string word[MAXN];
int maxpos, minpos;
int longest, shortest = 2147483647;
int i;

int main()
{
	while (cin >> word[i])
	{
		int len = word[i].length();
		if (len > longest)
		{
			maxpos = i;
			longest = len;
		}
		if (len < shortest)
		{
			minpos = i;
			shortest = len;
		}
		i++;
	}
	cout << word[maxpos] << endl << word[minpos];
	return 0;
}
