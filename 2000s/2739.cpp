#include <iostream>

using namespace std;

int main()
{
	int a;
	int counter = 1;

	cin >> a;

	while (counter < 10)
	{
		cout << a << " * " << counter << " = " << a * counter << endl;
		counter++;
	}
}