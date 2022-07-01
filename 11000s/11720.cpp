#include <iostream>
#include <string>

using namespace std;

int main()
{
	int counters = 0;
	string numbers = "";
	int total = 0;
	int curr_number = 0;
	string curr_char = "";

	cin >> counters;
	cin >> numbers;	

	while(counters--)
	{
		curr_char = numbers[counters];
		total = total + stoi(curr_char);
	}
	
	cout << total;
}