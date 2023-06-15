#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> area;
int n, l;

int main()
{
    int path = 0;
    cin >> n >> l;

    area.resize(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> area[i][j];
        }
    }

    // 가로 방향 길 먼저 체크
    for(int k = 0; k < n; k++)
    {
        vector <bool> is_ramp(n);
        bool flag = true;

        for(int i = 1; i < n; i++)
        {
            if(abs(area[k][i] - area[k][i-1]) > 1) // 높이차이가 2 이상이면 break;
            {
                flag = false;
                break;
            }
            else if(area[k][i] < area[k][i-1]) // 내리막길일 경우
            {
                int curri = i;
                if(0 <= curri+l && curri+l <= n)
                {
                    for(curri; curri < i+l; curri++)
                    {
                        if(is_ramp[curri] || area[k][curri] != area[k][i])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                    {
                        for(curri = i; curri < i+l; curri++)
                        {
                            is_ramp[curri] = true;
                        }
                        i += l-1;
                    }
                }
                else
                {
                    flag = false;
                }
            }
            else if(area[k][i] > area[k][i-1]) // 오르막길일 경우
            {
                int curri = i-1;
                if(0 <= curri-l+1 && curri-l < n)
                {
                    for(curri; curri >= i-l; curri--)
                    {
                        if(is_ramp[curri] || area[k][curri] != area[k][i-1])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                    {
                        for(curri = i-1; curri >= i-l; curri--)
                        {
                            is_ramp[curri] = true;
                        }
                    }
                }
                else
                {
                    flag = false;
                }
            }
        }

        if(flag)
        {
            path++;
        }
    }

    // 세로 방향 길 체크
    for(int k = 0; k < n; k++)
    {
        vector <bool> is_ramp(n);        
        bool flag = true;
        
        for(int i = 1; i < n; i++)
        {
            if(abs(area[i][k] - area[i-1][k] > 1)) // 높이차이가 2 이상이면 break;
            {
                flag = false;
                break;
            }
            else if(area[i][k] < area[i-1][k]) // 내리막일 경우
            {
                int curri = i;
                if(0 <= curri+l && curri+l <= n)
                {
                    for(curri; curri < i+l; curri++)
                    {
                        if(is_ramp[curri] || area[curri][k] != area[i][k])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                    {
                        for(curri = i; curri < i+l; curri++)
                        {
                            is_ramp[curri] = true;
                        }
                        i += l-1;
                    }
                }
                else
                {
                    flag = false;
                }
            }
            else if(area[i][k] > area[i-1][k]) // 오르막길일 경우
            {
                int curri = i-1;
                if(0 <= curri-l+1 && curri-l < n)
                {
                    for(curri; curri >= i-l; curri--)
                    {
                        if(is_ramp[curri] || area[curri][k] != area[i-1][k])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                    {
                        for(curri = i-1; curri >= i-1; curri--)
                        {
                            is_ramp[curri] = true;
                        }
                    }
                }
                else
                {
                    flag = false;
                }
            }
        }

        if(flag)
        {
            path++;
        }
    }

    cout << path;
}