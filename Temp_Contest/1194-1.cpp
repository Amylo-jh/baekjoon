#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    vector <char> ch = {'K','O','R','E','A'};
    int counter = 0;
    int index = 0;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ch[index])
        {
            counter++;
            index++;
            index %= 5;
        }
    }

    cout << counter;
}