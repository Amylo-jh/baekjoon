#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int len = str.length();

    int pos = -1;
    if(str[len-1] == 'a' || str[len-1] == 'e'
    || str[len-1] == 'i' || str[len-1] == 'o'
    || str[len-1] == 'u' || str[len-1] == 'n'
    || str[len-1] == 's')
    {
        int counter = 2;        
        for(int i = len-1; i >= 0; i--)
        {
            if(str[i] == 'a' || str[i] == 'e'
            || str[i] == 'i' || str[i] == 'o'
            || str[i] == 'u')
            {
                counter--;
                if(counter == 0)
                {
                    cout << i+1;
                    return 0;
                }
            }
        }

        cout << -1;
        return 0;
    }

    for(int i = len-1; i >= 0; i--)
    {
        if(str[i] == 'a' || str[i] == 'e'
        || str[i] == 'i' || str[i] == 'o'
        || str[i] == 'u')
        {
            cout << i+1;
            return 0;
        }
    }

    cout << -1;
}