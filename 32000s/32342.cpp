#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string str;
        cin >> str;
        int count = 0;
        int len = str.length();
        for(int i = 0; i < len-2; i++)
        {
            if(str[i] == 'W' && str[i+1] == 'O' && str[i+2] == 'W')
            {
                count++;
            }
        }
        cout << count << '\n';
    }
}