#include <iostream>

using namespace std;

bool check_num(int i)
{
    int combo = 0;
    while(i != 0)
    {
        if(i % 10 == 6)
        {
            combo++;
            if(combo >= 3)
            {
                break;
            }
        }
        else
        {
            combo = 0;
        }
        i = i / 10;
    }

    return (combo >= 3);
}

int main()
{
    int i = 666;
    int n;
    int count = 0;
    cin >> n;

    for(i; count != n; i++)
    {
        if(check_num(i))
        {
            count++;
        }
    }

    i--;
    cout << i;
}