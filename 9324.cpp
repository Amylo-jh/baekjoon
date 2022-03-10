#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        int chars[26] = {0};
        string str;
        cin >> str;

        int length = str.length();

        for(int i = 0; i < length; i++)
        {
            char temp = str[i] - 65;
            chars[temp]++;

            if(chars[temp] == 3)
            {
                if(str[i+1] != temp + 65)
                {
                    cout << "FAKE" << endl;
                    break;
                }
                i++;
                chars[temp] = 0;
            }
            if(i == length - 1)
            {
                cout << "OK" << endl;
            }
        }
    }
}