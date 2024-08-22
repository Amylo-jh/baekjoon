#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> arr;

bool find_bingo()
{
    int bingo_count = 0;

    for(int i = 0; i < 5; i++)
    {
        bool bingo = true;
        for(int j = 0; j < 5; j++)
        {
            if(arr[i][j] != 0)
            {
                bingo = false;
                break;
            }
        }

        bingo_count += bingo;
    }

    for(int i = 0; i < 5; i++)
    {
        bool bingo = true;
        for(int j = 0; j < 5; j++)
        {
            if(arr[j][i] != 0)
            {
                bingo = false;
                break;
            }
        }

        bingo_count += bingo;
    }

    bool bingo = true;
    for(int i = 0; i < 5; i++)
    {
        if(arr[i][i] != 0)
        {
            bingo = false;
        }

    }
    bingo_count += bingo;

    bingo = true;
    for(int i = 0; i < 5; i++)
    {
        if(arr[i][4 - i] != 0)
        {
            bingo = false;
        }

    }
    bingo_count += bingo;

    return bingo_count >= 3;
}

int main()
{
    arr.resize(5, vector <int> (5, 0));
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= 25; i++)
    {
        int num;
        cin >> num;

        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                if(arr[j][k] == num)
                {
                    arr[j][k] = 0;
                    j = k = 5;
                }
            }
        }

        if(find_bingo())
        {
            cout << i;
            break;
        }
    }
}