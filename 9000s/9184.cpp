#include <iostream>
#include <vector>
using namespace std;

int arr[22][22][22];

int w(int a, int b, int c)
{
    if(arr[a][b][c])
    {
        return arr[a][b][c];
    }

    if(a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if(a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }
    if(a < b && b < c)
    {
        return w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }

    return w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i <= 20; i++)
    {
        for(int j = 1; j <= 20; j++)
        {
            for(int k = 1; k <= 20; k++)
            {
                arr[i][j][k] = w(i, j, k);
            }
        }
    }

    while(1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == -1 &&  b == -1 && c == -1)
        {
            break;
        }

        cout << "w(" << a << ", "<< b << ", "<< c << ") = ";
        if(a <= 0 || b <= 0 || c <= 0)
        {
            cout << 1;
        }
        else if(a > 20 || b > 20 || c > 20)
        {
            cout << arr[20][20][20];
        }
        else
        {
            cout << arr[a][b][c];
        }
        cout << "\n";
    }
}