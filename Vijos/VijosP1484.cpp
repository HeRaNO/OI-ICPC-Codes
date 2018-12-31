#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	char isbn[14];
	int isbnhao[12];
	int sum = 0, yu, i;
	gets(isbn);
	if (isbn[12] == 'X')
	{
		isbnhao[0] = isbn[0] - 48;
		for (i = 1; i <= 3; i++) isbnhao[i] = isbn[i + 1] - 48;
		for (i = 4; i <= 8; i++) isbnhao[i] = isbn[i + 2] - 48;
		isbnhao[9] = 10;
	}
	else
	{
		isbnhao[0] = isbn[0] - 48;
		for (i = 1; i <= 3; i++) isbnhao[i] = isbn[i + 1] - 48;
		for (i = 4; i <= 8; i++) isbnhao[i] = isbn[i + 2] - 48;
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
}