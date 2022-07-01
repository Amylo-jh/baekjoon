#pragma warning (disable:4996)

#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
	vector <int> num;
	int n, temp, i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		num.push_back(temp);
	}

	sort(num.begin(), num.end(), greater<>());

	for (i = 0; i < n; i++)
	{
		printf("%d\n", num.back());
		num.pop_back();
	}
}
