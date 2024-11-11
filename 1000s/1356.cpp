#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    if(str.size() == 1)
    {
        cout << "NO";
        return 0;
    }

    for(int i = 1; i < str.size(); i++)
    {
        long long left = 1;
        long long right = 1;
        for(int j = 0; j < i; j++)
        {
            left *= str[j] - '0';
        }
        for(int j = i; j < str.size(); j++)
        {
            right *= str[j] - '0';
        }

        if(left == right)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}