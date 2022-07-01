#include <iostream>

using namespace std;

int main()
{
	int sugar_5 = 0;
	int sugar_3 = 0;
	int total_kg = 0;
	int remain_kg = 0;
	int flag = 0;

	cin >> total_kg;

	sugar_5 = total_kg / 5;

	while (sugar_5 >= 0)
	{
		remain_kg = total_kg - sugar_5 * 5;
		if (!(remain_kg % 3))
		{
			sugar_3 = remain_kg / 3;
			break;
		}
		sugar_5--;
		if (sugar_5 < 0)
		{
			flag = 1;
		}
	}

	if (flag == 0)
	{
		cout << sugar_5 + sugar_3;
	}
	else
	{
		cout << "-1";
	}
}