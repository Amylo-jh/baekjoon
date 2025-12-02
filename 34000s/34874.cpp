#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int>> arr(n, vector <int>(m));
    vector <int> count(m);
    for(int i = 0; i < n; i++)
    {
        int max_score = 0;
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            max_score = max(max_score, arr[i][j]);
        }
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] != max_score)
            {
                count[j]++;
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        cout << count[i] << " ";
    }
}