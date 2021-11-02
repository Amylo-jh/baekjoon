#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a[3];
	int d[3];
	
	while (1)
	{
		cin >> a[0] >> a[1] >> a[2];
		if (a[0] + a[1] + a[2] == 0)
		{
			break;
		}

		sort(a, a + 3);
		a[0] = a[0] * a[0];
		a[1] = a[1] * a[1];
		a[2] = a[2] * a[2];

		if (a[0] + a[1] == a[2])
		{
			cout << "right" << endl;
		}
		else
		{
			cout << "wrong" << endl;
		}

	}
	

	

}