#include <iostream>

using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	int counter_a = 0;
	int counter_b = 0;

	cin >> a;

	for(counter_a = 1; counter_a <= a; counter_a++)
	{
		for(counter_b = 1; counter_b <= counter_a; counter_b++)
		{
			printf("*");
		}
		printf("\n");
	}
}