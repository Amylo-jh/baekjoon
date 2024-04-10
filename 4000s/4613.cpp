#include <iostream>
#include <string>

using namespace std;

int main()
{
    while(1)
    {
        string str;
        int sum = 0;
        getline(cin, str);

        if(str == "#")
        {
            break;
        }
        for(int i = 0; i < str.length(); i++)
        {
            int num = str[i] - 'A' + 1;
            if(str[i] == ' ')
            {
                num = 0;
            }
            sum += num * (i + 1);
        }

        cout << sum << '\n';
    }
}