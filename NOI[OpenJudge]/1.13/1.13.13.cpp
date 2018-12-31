//Code By HeRaNO
#include<iostream>
using namespace std;
int main()
{
	int qian, yb, ws, es, s, w, y;
	cin >> qian;
	yb = qian / 100;
	qian = qian - 100 * yb;
	ws = qian / 50;
	qian = qian - 50 * ws;
	es = qian / 20;
	qian = qian - 20 * es;
	s = qian / 10;
	qian = qian - 10 * s;
	w = qian / 5;
	qian = qian - 5 * w;
	cout << yb << endl << ws << endl << es << endl << s << endl << w << endl << qian;
}
