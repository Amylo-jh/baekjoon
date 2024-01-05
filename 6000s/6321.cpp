#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == 'Z')
            {
                str[j] = 'A';
                continue;
            }
            str[j]++;

        }
        cout << "String #" << i << "\n";
        cout << str << "\n";
        cout << "\n";
    }
}