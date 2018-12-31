//Code By HeRaNO
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n, i, maxfen, maxpos;
	cin >> n;
	int fen[n];
	string name[n];
	for (i = 0; i < n; i++)
		cin >> fen[i] >> name[i];
	maxfen = fen[0];
	for (i = 1; i < n; i++)
	{
		if (fen[i] > maxfen)
		{
			maxfen = fen[i];
			maxpos = i;
		}
	}
	cout << name[maxpos];
	return 0;
}
