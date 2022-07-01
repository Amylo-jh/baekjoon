#include <iostream>

using namespace std;

int main()
{
    int nan[9];
    int total = 0;
    int not_nan[2];

    for(int i = 0; i < 9; i++)
    {
        cin >> nan[i];
        total = total + nan[i];
    }

    for(int i = 0;i<9-1;i++)
    {
        for(int j= i+1;j<9;j++)
        {
            if(total - nan[i] - nan[j] == 100)
            {
                not_nan[0] = i;
                not_nan[1] = j;
            }
        }
    }

    for(int i = 0;i<9;i++)
    {
        if(i != not_nan[0] && i != not_nan[1])
        {
            cout << nan[i] << endl;
        }
    }


}