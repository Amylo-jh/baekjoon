#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	int tmp;
	int counter = 0;
	vector <int> x;

	long long total = 0;

	cin >> n;

	while (counter < n)
	{
		cin >> tmp;
		x.push_back(tmp);
		counter++;
	}
	counter = 0;
	tmp = 0;

	while (counter < n)
	{
		while (tmp < n)
		{
			total = total + abs(x[counter] - x[tmp]);
			tmp++;
		}
		counter++;
		tmp = 0;
	}
	cout << total;
}