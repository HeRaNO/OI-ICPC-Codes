#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 10010
using namespace std;

int n, T;
map <string, long long> m;
map <string, long long> :: iterator it;
string in;

int main()
{
	while (getline(cin, in))
	{
		n++;
		it = m.find(in);
		if (it == m.end()) m.insert(make_pair(in, 1));
		else it->second++;
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		cout << it->first;
		printf(" %.4lf\n", (double)it->second / (double)n * 100.0);
	}
	return 0;
}
