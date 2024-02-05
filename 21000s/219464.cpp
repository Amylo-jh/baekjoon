#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;
    for(int i = str.length() - 5; i < str.length(); i++)
    {
        cout << str[i];
    }
}