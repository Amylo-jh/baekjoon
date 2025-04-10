#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector <vector <int>> arr(n, vector <int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    while(1)
    {
        vector <vector <int>> newarr(n/2, vector <int>(n/2));
        for(int i = 0; i < n; i = i+2)
        {
            for(int j = 0; j < n; j = j+2)
            {
                vector <int> temp = {arr[i][j], arr[i][j+1], arr[i+1][j], arr[i+1][j+1]};
                sort(temp.begin(), temp.end());
                newarr[i/2][j/2] = temp[2];
            }
        }

        n /= 2;
        if(n == 1)
        {
            cout << newarr[0][0];
            return 0;
        }
        arr = newarr;
    } 
}