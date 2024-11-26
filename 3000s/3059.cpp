#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string str;
        cin >> str;

        vector <bool> arr(26, true);
        for(int i = 0; i < str.length(); i++)
        {
            arr[str[i] - 'A'] = false;
        }

        int sum = 0;
        for(int i = 0; i < 26; i++)
        {
            if(arr[i])
            {
                sum += i + 'A';
            }
        }

        cout << sum << "\n";
    }
}