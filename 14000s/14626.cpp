#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int sum = 0, pos;
    for(int i = 0; i < 13; i++)
    {
        if(str[i] == '*')
        {
            pos = i;
        }
        else
        {
            int num = str[i] - '0';
            if(i % 2)
            {
                num *= 3;
            }
            sum += num;
        }
    }

    if(pos % 2)
    {
        pos = 3;
    }
    else
    {
        pos = 1;
    }
    for(int i = 0; i < 10; i++)
    {
        if((sum + i*pos) % 10 == 0)
        {
            cout << i;
            break;
        }
    }
    
}