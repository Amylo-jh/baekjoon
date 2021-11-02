#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a;
	string b;
	int length;
	int counter = 0;

	while (1)
	{
		cin >> a;
		if (a == "0")
		{
			break;
		}
		b = a;
		length = a.length();

		while (length--)
		{
			b[length] = a[counter];
			counter++;
		}
		if (a == b)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
		counter = 0;
	}
}