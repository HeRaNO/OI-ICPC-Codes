#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	char isbn[13];
	int isbnhao[11];
	int sum = 0, yu, i;
	gets(isbn);
	if (isbn[12] == 'X')
	{
		isbnhao[0] = isbn[0] - 48;
		isbnhao[1] = isbn[2] - 48;
		isbnhao[2] = isbn[3] - 48;
		isbnhao[3] = isbn[4] - 48;
		isbnhao[4] = isbn[6] - 48;
		isbnhao[5] = isbn[7] - 48;
		isbnhao[6] = isbn[8] - 48;
		isbnhao[7] = isbn[9] - 48;
		isbnhao[8] = isbn[10] - 48;
		isbnhao[9] = 10;
	}
	else
	{
		isbnhao[0] = isbn[0] - 48;
		isbnhao[1] = isbn[2] - 48;
		isbnhao[2] = isbn[3] - 48;
		isbnhao[3] = isbn[4] - 48;
		isbnhao[4] = isbn[6] - 48;
		isbnhao[5] = isbn[7] - 48;
		isbnhao[6] = isbn[8] - 48;
		isbnhao[7] = isbn[9] - 48;
		isbnhao[8] = isbn[10] - 48;
		isbnhao[9] = isbn[12] - 48;
	}
	for (i = 0; i <= 8; i++)
		sum = sum + isbnhao[i] * (i + 1);
	yu = sum % 11;
	if (isbnhao[9] == yu) cout << "Right";
	else
	{
		if (yu == 10) isbn[12] = 'X';
		else isbn[12] = (yu + 48);
		for (i = 0; i <= 12; i++) cout << isbn[i];
	}
	cout << endl;
	return 0;
}
