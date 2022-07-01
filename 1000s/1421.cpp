#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, c, w;
	int counter = 0;
	vector <int> tree;
	int cut = 0;
	int money = 0;
	int max_money = 0;

	cin >> n >> c >> w;

	for (counter = 0; counter < n; counter++)
	{
		int tmp;
		cin >> tmp;
		tree.push_back(tmp);
	}

	sort(tree.begin(), tree.end());

	for (int set = tree[n - 1]; set > 0; set--)
	{
		counter = 0;
		
		cut = tree[counter] / set;
		money = money + cut * set * w;
		if (tree[counter] % set)
		{
			cut++;
		}
		money = money - cut * c;
		
wa		if (max_money < money)
		{
			max_money = money;
		}
	}
	cout << max_money;
}