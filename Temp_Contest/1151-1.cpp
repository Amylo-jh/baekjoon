#include <iostream>

using namespace std;

int main()
{
    bool flag[3] = {false, false, false};
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            char ch;
            cin >> ch;
            if(ch == 'w')
            {
                flag[0] = true;
            }
            else if(ch == 'b')
            {
                flag[1] = true;
            }
            else if(ch == 'g')
            {
                flag[2] = true;
            }
        }
    }

    if(flag[0])
    {
        cout << "chunbae";
    }
    else if(flag[1])
    {
        cout << "nabi";
    }
    else
    {
        cout << "yeongcheol";
    }
}