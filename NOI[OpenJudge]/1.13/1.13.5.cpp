//Code By HeRaNO
#include <iostream>
using namespace std;

int isp(int a)
{
	if (a % 2 == 0) return 0;
	for (int i = 3; i * i <= a; i += 2)
		if (a % i == 0) return 0;
	return 1;
}

int main()
{
	int arr[100], ct = 0;
	for (int i = 11; i <= 99; i += 11)
	{
		if (isp(i))
			arr[ct++] = i;
	}
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 0; j <= 90; j += 10)
			if (isp(i * 101 + j)) arr[ct++] = i * 101 + j;
	}
	int a;
	cin >> a;
	int c = 0;
	for (int i = 0; i < ct; i++)
		if (a >= arr[i]) c++;
	cout << c << endl;
	return 0;
}
