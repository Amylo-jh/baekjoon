#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void heapsort(vector <int> &num)
{
	int length = num.size();

	//초기 heap 구성
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		heapify(num, i);
	}
}

void heapify(vector <int> &num, int i)
{
	int pointer = i;
	int left = i * 2 + 1;
	int right = i * 2 + 2;

	if(left < n && )
}

int main()
{
	// cin 말고 fast io 하는방법 찾기
	// 정렬 시간복잡도, 병합정렬 하는방법 찾아보기

	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	vector <int> num;
	int counter = 0;
	int length = 0;
	int tmp;

	cin >> counter;

	for (int input = 0; input < counter; input++)
	{
		cin >> tmp;
		num.push_back(tmp);
	}
	length = num.size();

	heapsort(num);





	for (int input = 0; input < counter; input++)
	{
		cout << num[input] << endl;
	}
}