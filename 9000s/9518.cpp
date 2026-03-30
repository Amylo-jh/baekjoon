#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int r, s, answer = 0, max_handshake = 0;
    cin >> r >> s;
    vector<vector<bool>> arr(r, vector<bool>(s));
    int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < s; j++)
        {
            if (str[j] == 'o')
            {
                arr[i][j] = true;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (arr[i][j])
            {
                for (int k = 0; k < 8; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (0 <= ny && ny < r && 0 <= nx && nx < s)
                    {
                        if (arr[ny][nx])
                        {
                            answer++;
                        }
                    }
                }
            }
            else
            {
                int count = 0;
                for (int k = 0; k < 8; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (0 <= ny && ny < r && 0 <= nx && nx < s)
                    {
                        if (arr[ny][nx])
                        {
                            count++;
                        }
                    }
                }
                max_handshake = max(max_handshake, count);
            }
        }
    }
    answer /= 2;
    answer += max_handshake;
    cout << answer;
}