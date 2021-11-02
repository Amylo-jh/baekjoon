#include <iostream>
// #include <algorithm>

using namespace std;

int main()
{
	int x[4], y[4];

	cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

//	sort(x, x + 3);
//	sort(y, y + 3);

	if (x[0] == x[1])
	{
		x[3] = x[2];
	}
	else
	{
		x[3] = x[0];
	}
	
	if (y[0] == y[1])
	{
		y[3] = y[2];
	}
	else
	{
		y[3] = y[0];
	}

	cout << x[3] << " " << y[3];
}