#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    bool result = true;
    string arr[5] = {"M","O","B","I","S"};
    for(int i = 0; i < 5; i++)
    {
        auto pos = str.find(arr[i]);
        if(pos == string::npos)
        {
            result = false;
        }
    }

    if(result)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}