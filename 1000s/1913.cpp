#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector <vector <int>> arr(n, vector <int>(n, 0));

    int y = n/2, x = n/2;
    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {-1, 0, 1, 0};
    int idx = 0;
    arr[y][x] = 1;
    
    int count = 2;
    int answer_y = n/2, answer_x = n/2;

    while(count <= n*n)
    {
        int ny = y + dy[(idx+1)%4];
        int nx = x + dx[(idx+1)%4];
        if(0 <= ny && ny < n && 0 <= nx && nx < n)
        {
            if(arr[ny][nx] == 0)
            {
                idx = (idx+1)%4;
                y = ny;
                x = nx;
                arr[y][x] = count;
            }
            else
            {
                y = y + dy[idx];
                x = x + dx[idx];
                arr[y][x] = count;
            }

            if(count == m)
            {
                answer_y = y;
                answer_x = x;
            }
            count++;
        }

    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << answer_y+1 << " " << answer_x+1 << "\n";
}