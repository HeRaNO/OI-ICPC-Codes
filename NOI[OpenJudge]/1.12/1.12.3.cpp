//Code By HeRaNO
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string name[n];
	float temp[n];
	int ke[n], i, num = 0;
	for (i = 0; i < n; i++)
		cin >> name[i] >> temp[i] >> ke[i];
	for (i = 0; i < n; i++)
	{
		if ((temp[i] >= 37.5) && (ke[i] == 1))
		{
			cout << name[i] << endl;
			num++;
		}
	}
	cout << num;
}
