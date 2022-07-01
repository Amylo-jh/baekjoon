#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	int length;

	getline(cin, str);
	length = str.length();

	int tmp;
	int flag = 0;
	int words = 0;

	if (str.empty())
	{
		cout << "0";;
		return 0;
	}
	for (int counter = 0; counter < length; counter++)
	{
		tmp = str[counter];
		if (tmp == 32)
		{
			words++;
		}
	}
	if (str[0] == ' ')
	{
		words--;
	}
	if (str[length - 1] == ' ')
	{
		words--;
	}
	words++;
	cout << words;

	//공백은 ascii로 32가 나온다

}