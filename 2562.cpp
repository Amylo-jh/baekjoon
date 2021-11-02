#include <iostream>

using namespace std;

int main()
{
	int num[9];
	int counter = 0;
	int pos = 0;
	int max = 0;

	while (counter < 9)
	{
		cin >> num[counter];
		counter++;
	}
	for (counter = 0; counter < 9; counter++)
	{
		if (num[counter] > max)
		{
			pos = counter;
			max = num[counter];
		}
	}
	cout << max << "\n" << pos + 1;
}