#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<vector<bool>> arr(5, vector<bool>(5, false));
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 5; j++)
        {
            if (str[j] == 'k')
            {
                arr[i][j] = true;
                count++;
            }
        }
    }
    if(count != 9)
    {
        cout << "invalid";
        return 0;
    }
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j])
            {
                for (int k = 0; k < 8; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (0 <= ny && ny < 5 && 0 <= nx && nx < 5)
                    {
                        if (arr[ny][nx])
                        {
                            cout << "invalid";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "valid";
}