#include <iostream>
#include <vector>

using namespace std;

int main()
{
    bool arr[101][101];
    for(int i = 0; i <= 100; i++)
    {
        for(int j = 0; j <= 100; j++)
        {
            arr[i][j] = false;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int j = a; j < c; j++)
        {
            for(int k = b; k < d; k++)
            {
                arr[j][k] = true;
            }
        }
    }

    int count = 0;
    for(int i = 0; i <= 100; i++)
    {
        for(int j = 0; j <= 100; j++)
        {
            if(arr[i][j])
            {
                count++;
            }
        }
    }

    cout << count;
}