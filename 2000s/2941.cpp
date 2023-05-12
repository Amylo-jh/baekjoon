#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int counter = 0;
    for(int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case 'c':
            if(i < str.length() - 1 && str[i+1] == '=')
            {                
                i++;
            }
            else if(i < str.length() - 1 && str[i+1] == '-')
            {                
                i++;
            }
            break;
        case 'd':
            if(i < str.length() - 2 && str[i+1] == 'z' && str[i+2] == '=')
            {                
                i += 2;
            }
            else if(i < str.length() - 1 && str[i+1] == '-')
            {                
                i++;
            }
            break;
        case 'l':
            if(i < str.length() - 1 && str[i+1] == 'j')
            {                
                i++;
            }
            break;
        case 'n':
            if(i < str.length() - 1 && str[i+1] == 'j')
            {                
                i++;
            }
            break;
        case 's':
            if(i < str.length() - 1 && str[i+1] == '=')
            {
                i++;
            }
            break;
        case 'z':
            if(i < str.length() - 1 && str[i+1] == '=')
            {
                i++;
            }
            break;
        default:
            break;
        }
        counter++;
    }

    cout << counter;
}