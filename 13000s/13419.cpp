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

        string first, second;
        for(int i = 0; i < str.size(); i++)
        {
            if(i % 2 == 0)
            {
                first += str[i];
            }
            else
            {
                second += str[i];
            }
        }
        if(str.size() % 2 == 1)
        {
            for(int i = 0; i < str.size(); i++)
            {
                if(i % 2 == 0)
                {
                    second += str[i];
                }
                else
                {
                    first += str[i];
                }
            }
        }
        
        cout << first << "\n" << second << "\n";
    }
}