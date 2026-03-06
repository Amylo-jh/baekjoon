#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <vector <bool>> arr(501, vector <bool>(501));
    int n, x1, y1, x2, y2;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1; x < x2; x++)
        {
            for(int y = y1; y < y2; y++)
            {
                arr[x][y] = true;
            }
        }
    }
    int count = 0;
    for(int i = 0; i <= 500; i++)
    {
        for(int j = 0; j <= 500; j++)
        {
            if(arr[i][j])
            {
                count++;
            }
        }
    }
    cout << count;
}