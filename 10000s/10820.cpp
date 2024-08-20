#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    while(getline(cin, str))
    {
        int lo = 0, up = 0, num = 0, space = 0;
        for(int i = 0; i < str.length(); i++)
        {
            if('a' <= str[i] && str[i] <= 'z')
            {
                lo++;
            }
            else if('A' <= str[i] && str[i] <= 'Z')
            {
                up++;
            }
            else if('0' <= str[i] && str[i] <= '9')
            {
                num++;
            }
            else if(str[i] == ' ')
            {
                space++;
            }
        }

        cout << lo << " " << up << " " << num << " " << space << "\n";
    }
}