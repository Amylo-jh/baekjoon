#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <vector <int>> arr(n);

    for(int i = 0; i < n; i++)
    {
        arr[i].resize(3);
        for(int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    int max_prize = 0;
    for(int i = 0; i < n; i++)
    {
        int max_val = 0;
        if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
        {
            max_prize = max(max_prize, 10000 + arr[i][0]*1000);
            continue;
        }

        if(arr[i][0] == arr[i][1])
        {
            max_prize = max(max_prize, 1000 + arr[i][0]*100);
            continue;
        }
        if(arr[i][1] == arr[i][2])
        {
            max_prize = max(max_prize, 1000 + arr[i][1]*100);
            continue;
        }
        if(arr[i][2] == arr[i][0])
        {
            max_prize = max(max_prize, 1000 + arr[i][2]*100);
            continue;
        }

        max_prize = max(max_prize, max(arr[i][0], max(arr[i][1], arr[i][2]))*100 );
    }

    cout << max_prize;
}