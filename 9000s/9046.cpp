#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    cin.ignore();
    while(tc--)
    {
        string str;
        vector <int> arr(26);
        getline(cin, str);
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] != ' ')
            {
                arr[str[i] - 'a']++;
            }
        }
        char max_char = '?';
        int max_count = 0;
        for(int i = 0; i < 26; i++)
        {
            if(arr[i] > max_count)
            {
                max_char = 'a' + i;
                max_count = arr[i];
            }
            else if(arr[i] == max_count)
            {
                max_char = '?';
            }
        }
        cout << max_char << "\n";
    }
}