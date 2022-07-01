#include <iostream>
#include <string>

using namespace std;

int main()
{
	string cipher = "";
	int stick = 0;
	int counter = 1;

	cin >> stick >> cipher;
	int size = cipher.size();
	for (counter = 0; counter < size; counter = counter + stick)
	{
		cout << cipher[counter];
	}
}