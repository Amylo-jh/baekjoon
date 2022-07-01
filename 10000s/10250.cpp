#include <iostream>

using namespace std;

int main()
{
	int testcase, h, w, n;
	int room_yy;
	int room_xx;
	int room_number;

	cin >> testcase;

	while (testcase--)
	{
		cin >> h >> w >> n;

		room_yy = n % h;
		if (room_yy == 0)
		{
			room_yy = h;
		}

		room_xx = n / h + 1;
		if (n % h == 0)
		{
			room_xx--;
		}
		room_number = room_yy * 100 + room_xx;
		
		cout << room_number << "\n";
	}
}