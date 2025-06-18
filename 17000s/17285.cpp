#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int len = str.length();

    string new_str;
    for(int i = 0; i <= 128; i++)
    {
        new_str = "";
        for(int j = 0; j < len; j++)
        {
            new_str += str[j] ^ i;
        }
        string temp = new_str.substr(0, 8);
        if(temp == "CHICKENS")
        {
            cout << new_str;
            break;
        }
    }   
}