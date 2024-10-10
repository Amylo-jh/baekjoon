#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;

    vector <int> arr(26);
    for(int i = 0; i < str.size(); i++)
    {
        arr[str[i]-'a']++;
    }

    bool even = false;
    bool odd = false;
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] == 0)
        {
            continue;
        }
        if(arr[i] % 2 == 0)
        {
            even = true;
        }
        else
        {
            odd = true;
        }
    }

    if(even && odd)
    {
        cout << "2";
    }
    else if(even)
    {
        cout << "0";
    }
    else
    {
        cout << "1";
    }
}