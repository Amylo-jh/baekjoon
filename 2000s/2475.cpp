#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e;

	a = a * a;
	b = b * b;
	c = c * c;
	d = d * d;
	e = e * e;

	f = (a + b + c + d + e) % 10;

	cout << f;
}