#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <vector <bool>> arr;

void init(int n, int y, int x)
{
    if(n == 1)
    {
        return;
    }
    else
    {
        for(int i = n/3+y; i < n/3*2+y; i++)
        {
            for(int j = n/3+x; j < n/3*2+x; j++)
            {
                arr[i][j] = true;
            }
        }
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i == j && i == 1)
                {
                    continue;
                }
                else
                {
                    init(n/3, y+(n/3*i), x+(n/3*j));
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        arr[i].resize(n);
    }
    
    init(n, 0, 0);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j])
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << "\n";
    }
}