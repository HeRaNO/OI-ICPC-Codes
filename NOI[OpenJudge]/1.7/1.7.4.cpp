//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string p1, p2;
	while (n--)
	{
		cin >> p1 >> p2;
		if (p1 == "Rock")
		{
			if (p2 == "Scissors")  cout << "Player1" << endl;
			else if (p2 == "Rock") cout << "Tie" << endl;
			else cout << "Player2" << endl;
		}
		else if (p1 == "Scissors")
		{
			if (p2 == "Paper")  cout << "Player1" << endl;
			else if (p2 == "Scissors") cout << "Tie" << endl;
			else cout << "Player2" << endl;
		}
		else
		{
			if (p2 == "Scissors")  cout << "Player2" << endl;
			else if (p2 == "Paper")  cout << "Tie" << endl;
			else cout << "Player1" << endl;
		}
	}
	return 0;
}
