#include <iostream>
#include <string>

using namespace std;

int main()
{
    while(!cin.eof())
    {
        string str;
        getline(cin, str);
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == 'i')
            {
                str[i] = 'e';
            }
            else if(str[i] == 'I')
            {
                str[i] = 'E';
            }
            else if(str[i] == 'e')
            {
                str[i] = 'i';
            }
            else if(str[i] == 'E')
            {
                str[i] = 'I';
            }
        }
        cout << str << "\n";
    }
}