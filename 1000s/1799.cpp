#include <iostream>
#include <vector>

using namespace std;

int n;
int counter = 0;
vector <vector <bool>> arr;

int sum = 0;

int bishop(int th, int size)
{
    if(th >= 2*n-1)
    {
        sum = max(sum, size);
    }
    else
    {
        bool flag = false;

        for(int j = 0; j < )
    }
}

int main()
{
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        arr[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            if(temp)
            {
                arr[i][j] = true;
            }
        }
    }
    
    bishop(0, 0);
    cout << sum;
}