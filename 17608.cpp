#include <iostream>

using namespace std;

int main()
{
	int array[100000];
	int given_stick = 0;

	int counter = 0;
	int look_stick_count = 0;
	int max_looked_stick_height = 0;

	cin >> given_stick;

	while (given_stick--)
	{
		cin >> array[counter];
		counter++;
	}

	while (counter--)
	{
		if (array[counter] > max_looked_stick_height)
		{
			max_looked_stick_height = array[counter];
			look_stick_count++;
		}
	}

	cout << look_stick_count;
	
}