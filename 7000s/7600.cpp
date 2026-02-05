#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        string str;
        getline(cin, str);
        if (str == "#")
        {
            return 0;
        }
        vector<int> arr(26);
        for (char ch : str)
        {
            if ('a' <= ch && ch <= 'z')
            {
                arr[ch - 'a']++;
            }
            else if ('A' <= ch && ch <= 'Z')
            {
                arr[ch - 'A']++;
            }
        }

        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (arr[i])
            {
                count++;
            }
        }
        cout << count << "\n";
    }
}