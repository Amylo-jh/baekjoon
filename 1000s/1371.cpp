#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector <int> arr(26);
    string str;
    while(cin >> str)
    {
        for(char ch : str)
        {
            arr[ch-'a']++;
        }
    }

    int max_value = 0;
    for(int i = 0; i < 26; i++)
    {
        max_value = max(max_value, arr[i]);
    }

    for(int i = 0; i < 26; i++)
    {
        if(max_value == arr[i])
        {
            cout << char('a' + i);
        }
    }
}