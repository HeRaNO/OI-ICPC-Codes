#include <iostream>
using namespace std;
int main()
{
	int A, B, C, N;
	cin >> N;
	C = N / 4;
	B = 0;
	A = 0;
	if (N % 4 == 0)
		cout << "A=" << A << " " << "B=" << B << " " << "C=" << C;
	else if (N % 4 == 1)
	{
		B++;
		C--;
		cout << "A=" << A << " " << "B=" << B << " " << "C=" << C;
	}
	else if (N % 4 == 2)
	{
		A++;
		C--;
		cout << "A=" << A << " " << "B=" << B << " " << "C=" << C;
	}
	else if (N % 4 == 3)
	{
		B++;
		A++;
		C -= 2;
		cout << "A=" << A << " " << "B=" << B << " " << "C=" << C;
	}
	return 0;
}
