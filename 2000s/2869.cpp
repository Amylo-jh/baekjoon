#include <iostream>

using namespace std;

int main()
{
	int a, b, v;
	int day;

	cin>>a>>b>>v;

	day = (v - a) / (a - b);
	day++;
	if ((v - a) % (a-b) != 0)
	{
		day++;
	}

	cout << day;

}