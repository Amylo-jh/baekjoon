#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool arr[1000][1000];

int get_square(int n, int m, int s)
{
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1];
            if(arr[i][j])
            {
                flag = true;
            }
        }
    }

    if(flag)
    {
        s = get_square(n-1, m-1, s+1);
    }
    
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == '1')
            {
                arr[i][j] = true;
                counter = 1;
            }
        }
    }

    if(counter)
    {
        counter = get_square(n-1, m-1, 1);
    }

    cout << counter*counter;    
}