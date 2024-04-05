#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <vector <int>> arr(9);
vector <pair <int, int>> hole;
bool found = false;

bool check(pair <int, int> p)
{
    int y = p.first;
    int x = p.second;
    for(int i = 0; i < 9; i++)
    {
        if(i != x && arr[y][i] == arr[y][x])
        {
            return false;
        }
        if(i != y && arr[i][x] == arr[y][x])
        {
            return false;
        }
    }

    int sq_y = (y / 3) * 3;
    int sq_x = (x / 3) * 3;
    for(int i = sq_y; i < sq_y + 3; i++)
    {
        for(int j = sq_x; j < sq_x + 3; j++)
        {
            if(i == y && j == x)
            {
                continue;
            } 
            if(arr[i][j] == arr[y][x])
            {
                return false;
            }
        }
    }
    return true;
}


void sudoku (int n)
{
    if(n == hole.size())
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout << arr[i][j];
            }
            cout << "\n";
        }
        found = true;
        return;
    }

    int y = hole[n].first;
    int x = hole[n].second;
    for(int i = 1; i <= 9; i++)
    {
        arr[y][x] = i;
        if(check(hole[n]))
        {
            sudoku(n+1);
        }
        if(found)
        {
            return;
        }
    }

    arr[y][x] = 0;
    return;
}

int main()
{    
    for(int i = 0; i < 9; i++)
    {
        arr[i].resize(9);
        string temp;
        cin >> temp;
        for(int j = 0; j < 9; j++)
        {
            arr[i][j] = temp[j] - '0';
            if(arr[i][j] == 0)
            {
                hole.push_back({i, j});
            }
        }
    }

    sudoku(0);
}