#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector <vector <int>> arr;

bool check_y(int y, int x)
{
    if(n <= y + 2)
    {
        return false;
    }
    if(arr[y][x] == 10 || arr[y+1][x] == 10 || arr[y+2][x] == 10)
    {
        return false;
    }
    if(0 <= y-1 && arr[y-1][x] != 10)
    {
        return false;
    }
    
    return true;
}

bool check_x(int y, int x)
{
    if(m <= x + 2)
    {
        return false;
    }
    if(arr[y][x] == 10 || arr[y][x+1] == 10 || arr[y][x+2] == 10)
    {
        return false;
    }
    if(0 <= x-1 && arr[y][x-1] != 10)
    {
        return false;
    }

    return true;
}

int main()
{
    cin >> n >> m;
    arr.resize(n, vector <int> (m));
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
        {
            if(str[j] == '.')
            {
                arr[i][j] = 0;
            }
            else if(str[j] == '#')
            {
                arr[i][j] = 10;
            }
        }
    }

    vector <pair <int, int>> answer;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(check_x(i, j) || check_y(i, j))
            {
                answer.push_back({i+1, j+1});
            }
        }
    }

    cout << answer.size() << "\n";
    for(pair <int, int> p : answer)
    {
        cout << p.first << " " << p.second << "\n";
    }
}