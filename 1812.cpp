#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	int total = 0;

	cin >> N;

	vector <int> x(N+1);
	vector <int> s(N+1);

	int tmp;
	for (int counter = 1; counter <= N; counter++)
	{
		cin >> s[counter];
		total = total + s[counter];
	}
	total = total / 2;
	x[N] = total;
	for (int counter = 1; counter < N; counter = counter + 2)
	{
		x[N] = x[N] - s[counter];
	}

	for (int counter = N; counter > 1; counter--)
	{
		x[counter - 1] = s[counter - 1] - x[counter];
	}
	
	for (int counter = 1; counter <= N; counter++)
	{
		cout << x[counter] << endl;
	}
}