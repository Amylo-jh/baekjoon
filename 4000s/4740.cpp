#include <iostream>
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        string str;
        getline(cin, str);
        if(str == "***")
        {
            break;
        }
        else
        {
            for(int i = str.length() - 1; i >= 0; i--)
            {
                cout << str[i];
            }
            cout << "\n";
        }
    }
}