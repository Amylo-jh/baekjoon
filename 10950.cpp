#include <iostream>

using namespace std;

int main()
{
	int counter;
	int a, b;

	cin >> counter;
	
	while (counter--)
	{
		cin >> a >> b;
		cout << a + b << endl;
	}
}