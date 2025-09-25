#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, max_count = 0, idx = 0, curr, prev;
    cin >> n;
    vector <vector <int>> arr(n+1);
    for(int i = 1; i <= n; i++)
    {
        arr[i].push_back(n);
        arr[i].push_back(i);
        for(int j = 2; ; j++)
        {
            arr[i].push_back(arr[i][j-2] - arr[i][j-1]);
            if(arr[i][j] < 0)
            {
                arr[i].pop_back();
                if(max_count < j)
                {
                    max_count = j;
                    idx = i;
                }
                break;
            }
        }
    }

    cout << max_count << "\n";
    for(int i : arr[idx])
    {
        cout << i << " ";
    }
}