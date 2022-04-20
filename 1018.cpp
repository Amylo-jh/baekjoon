#include <iostream>
#include <vector>

using namespace std;

int main()
{
    char chess[50][50];

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> chess[i];
    }

    int minimum_repaint = 2500;

    for(int i = 0; i <= n-8; i++)
    {
        for(int j = 0; j <= m-8; j++)
        {
            int black_change = 0;
            int white_change = 0;

            for(int k = i; k < i+8; k++)
            {
                for(int l = j; l < j+8; l++)
                {
                    if( (k + l) % 2) // 검사할 칸이 홀짝인지
                    {
                        if(chess[k][l] == 'B')
                        {
                            white_change++;
                        }
                        else
                        {
                            black_change++;
                        }
                    }
                    else
                    {
                        if(chess[k][l] == 'B')
                        {
                            black_change++;
                        }
                        else
                        {
                            white_change++;
                        }
                    }
                }
            }

            minimum_repaint = min(minimum_repaint, white_change);
            minimum_repaint = min(minimum_repaint, black_change);
        }
    }

    cout << minimum_repaint;
}