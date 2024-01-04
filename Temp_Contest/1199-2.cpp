#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;

    vector <int> arr(26);
    while(cin >> str)
    {
        for(int i = 0; i < str.length(); i++)
        {
            if('a' <= str[i] && str[i] <= 'z')
            {
                arr[str[i] - 'a']++;
            }
        }
    }

    int max_value = 0;
    for(int i = 0; i < 26; i++)
    {
        max_value = max(max_value, arr[i]);
    }

    cout << max_value;
}