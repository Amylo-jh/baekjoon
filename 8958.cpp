#include <iostream>
#include <string>

using namespace std;

int main()
{
	string test_result;
	int test_case = 0;
	int test_length = 0;
	int curr_score = 0;
	int prev_score = 0;
	int total_score = 0;
	int counter = 0;


	
	cin >> test_case;
	
	while (test_case--)
	{
		cin >> test_result;
		test_length = test_result.length();

		while (counter < test_length)
		{
			if (test_result[counter] == 'O')
			{
				curr_score = prev_score + 1;
				total_score = total_score + curr_score;

				prev_score = curr_score;
			}
			else
			{
				prev_score = 0;
			}

			counter++;
		}
		cout << total_score << endl;
		total_score = 0;
		prev_score = 0;
		counter = 0;
	}
}