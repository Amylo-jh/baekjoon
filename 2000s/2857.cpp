#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool flag = false;
    for(int i = 1; i <= 5; i++)
    {
        string str;
        cin >> str;

        for(int j = 0; j < str.length() - 2; j++)
        {
            if(str[j] == 'F' && str[j+1] == 'B' && str[j+2] == 'I')
            {
                flag = true;
                cout << i << " ";
                break;
            }
        }
    }

    if(!flag)
    {
        cout << "HE GOT AWAY!";
    }
}