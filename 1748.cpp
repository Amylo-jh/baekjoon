#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	int num = 0;
	int num_length;
	int counter = 0;
	int total_length = 0;
	// int place_value = 2;

	cin >> num;

	num_length = floor(log10(num)+1);
	
	while (counter+1 < num_length)
	{
		total_length = total_length + (counter + 1) * 9 * pow(10,counter);
		counter++;
	}
	total_length = total_length + (counter + 1) * ((num - pow(10, counter)) + 1);

	cout << total_length;
}