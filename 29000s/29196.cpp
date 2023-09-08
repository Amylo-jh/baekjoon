#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    str = str.substr(2, str.length()-2);

    cout << "YES" << "\n";
    int num1 = stoi(str);
    int num2 = 1;
    int temp = str.length();
    while(temp--)
    {
        num2 *= 10;
    }

    cout << num1 << " " << num2;
}