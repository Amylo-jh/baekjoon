#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str, newstr, target;
    cin >> str >> target;
    for(int i = 0; i < str.length(); i++)
    {
        if('0' <= str[i] && str[i] <= '9')
        {
            continue;
        }
        else
        {
            newstr += str[i];
        }
    }
    newstr.find(target) != string::npos ? cout << "1" : cout << "0";
}