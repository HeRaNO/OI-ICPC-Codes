#include <cstring>
#include <iostream>
using namespace std;

int T;
string d1[4], d2[4];

int main()
{
	cin >> T;
	while (T--)
	{
		int cnt = 0;
		for (int i = 0; i < 4; i++) cin >> d1[i];
		for (int i = 0; i < 4; i++) cin >> d2[i];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (d1[i] == d2[j]) cnt++;
		if (cnt >= 2) cout << "similar" << endl;
		else cout << "dissimilar" << endl;
	}
	return 0;
}