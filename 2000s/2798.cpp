#include <iostream>

using namespace std;

int main()
{
	int n = 0, m = 0;
	int curr_card_sum = 0;
	int max_card_sum = 0;

	cin >> n >> m;

	int card_num[100];
	int counter = 0;
	while (counter < n)
	{
		cin >> card_num[counter];
		counter++;
	}

	int index_1;
	int index_2;
	int index_3;

	for (index_1 = 0; index_1 < n-2; index_1++)
	{
		for (index_2 = index_1 + 1; index_2 < n - 1; index_2++)
		{
			for (index_3 = index_2 + 1; index_3 < n; index_3++)
			{
				curr_card_sum = card_num[index_1] + card_num[index_2] + card_num[index_3];
					if (m >= curr_card_sum && curr_card_sum > max_card_sum)
					{
						max_card_sum = curr_card_sum;
					}
			}

		}
	}
	cout << max_card_sum;
}