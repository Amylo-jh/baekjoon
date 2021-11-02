#include <iostream>

using namespace std;

int main()
{
	int a, b;

	cin >> a;
	b = a / 5;
	if (a % 5)
	{
		b++;
	}
	cout << b;

}