#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> num;
	int X;
	int length;
	int counter = 0;
	int tmp;

	cin >> length >> X;

	while (counter < length)
	{
		cin >> tmp;
		num.push_back(tmp);
		counter++;
	}
	counter = 0;
	while (counter < length)
	{
		if (num[counter] < X)
		{
			cout << num[counter] << " ";
		}
		counter++;
	}
}