#include <bits/stdc++.h>
#define MAXN 50
using namespace std;

int n, m, x, s[MAXN], usrs[MAXN], usrcnt, usrl, usrans[MAXN], stdl;
string usr, stdans;
bool no_solution;

int main(int argc, char const *argv[])
{
	ifstream fin(argv[1]), fout(argv[2]), fusr(argv[3]);
	fin >> n;
	m = n * (n - 1) >> 1;
	for (int i = 1; i <= m; i++) fin >> s[i];
	fout >> stdans;
	if (stdans == "Impossible") no_solution = true;
	getline(fusr, usr);
	usrl = usr.length();
	if (usr[0] == 'I' && !no_solution)
	{
		puts("Didn't find a solution to the input,but it has!");
		return 1;
	}
	if (usr == "Impossible" && stdans == "Impossible")
	{
		puts("Right!");
		return 0;
	}
	for (int i = 0; i < usrl; i++)
	{
		if (usr[i] == ' ') usrs[++usrcnt] = x, x = 0;
		else x = (x << 3) + (x << 1) + usr[i] - '0';
		if (usrcnt > n)
		{
			puts("More number than require!");
			return 1;
		}
	}
	if (x) usrs[++usrcnt] = x;
	if (usrcnt < n)
	{
		puts("Less number than require!");
		return 1;
	}
	int pos = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			usrans[++pos] = usrs[i] + usrs[j];
	sort(s + 1, s + m + 1);
	sort(usrans + 1, usrans + m + 1);
	for (int i = 1; i <= m; i++)
		if (s[i] != usrans[i])
		{
			puts("Wrong answer!");
			return 1;
		}
	puts("Right!");
	return 0;
}