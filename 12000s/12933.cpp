#include <iostream>
#include <string>

using namespace std;

int main()
{
    int quack[5] = {0}; // q, u, a, c, k;
    int duck = 0;
    int max_duck = 0;
    bool is_valid = true;
    string str;

    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if(is_valid == false)
        {
            break;
        }

        switch (ch)
        {
        case 'q':
            duck++;
            quack[1]++;
            break;
        
        case 'u':
            if(quack[1] == 0)
            {
                is_valid = false;
                break;
            }
            quack[1]--;
            quack[2]++;
            break;

        case 'a':
            if(quack[2] == 0)
            {
                is_valid = false;
                break;
            }
            quack[2]--;
            quack[3]++;
            break;

        case 'c':
            if(quack[3] == 0)
            {
                is_valid = false;
                break;
            }
            quack[3]--;
            quack[4]++;
            break;

        case 'k':
            if(quack[4] == 0)
            {
                is_valid = false;
                break;
            }
            duck--;
            quack[4]--;
            break;

        default:
            is_valid = false;
            break;
        }

        if(max_duck < duck)
        {
            max_duck = duck;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        if(quack[i] != 0)
        {
            is_valid = false;
        }
    }

    if(is_valid)
    {
        cout << max_duck;
    }
    else
    {
        cout << -1;
    }
}