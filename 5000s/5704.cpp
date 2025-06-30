#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    while(1)
    {
        getline(cin, str);
        if(str == "*")
        {
            break;
        }

        vector <bool> arr(26, false);
        bool answer = true;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] != ' ')
            {
                arr[str[i] - 'a'] = true;
            }
        }

        for(int i = 0; i < 26; i++)
        {
            answer &= arr[i];
        }

        if(answer)
        {
            cout << "Y\n";
        }
        else
        {
            cout << "N\n";
        }
    }
}