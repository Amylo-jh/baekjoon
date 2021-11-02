#include <iostream>

using namespace std;

int main()
{
	long long a, b, total;

	cin >> a >> b;
	total = (a + b) * (a - b);
	cout << total;
}