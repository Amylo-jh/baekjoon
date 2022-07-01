#include <iostream>
#include <string>

using namespace std;

int main()
{
	string asc = "1 2 3 4 5 6 7 8";
	string des = "8 7 6 5 4 3 2 1";

	string input;

	getline(cin, input);

	if (input.compare(asc) == 0)
	{
		cout << "ascending";
	}
	else if (input.compare(des) == 0)
	{
		cout << "descending";
	}
	else
	{
		cout << "mixed";
	}
}