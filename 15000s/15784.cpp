#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    a--;
    b--;
    vector <vector <int>> arr(n, vector <int> (n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        if(arr[i][b] > arr[a][b])
        {
            flag = true;
        }
        if(arr[a][i] > arr[a][b])
        {
            flag = true;
        }
    }

    if(flag)
    {
        cout << "ANGRY";
    }
    else
    {
        cout << "HAPPY";
    }
}