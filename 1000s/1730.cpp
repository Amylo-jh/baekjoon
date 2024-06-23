#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;

    vector <vector <int>> arr(n, vector <int> (n, 0));

    int y = 0;
    int x = 0;

    int dy, dx;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'U')
        {
            dy = -1;
            dx = 0;
        }
        else if(str[i] == 'D')
        {
            dy = 1;
            dx = 0;
        }
        else if(str[i] == 'L')
        {
            dy = 0;
            dx = -1;
        }
        else
        {
            dy = 0;
            dx = 1;
        }

        if(0 <= y+dy && y+dy < n && 0 <= x+dx && x+dx < n)
        {
            if(dy == 0)
            {
                arr[y][x] |= 1;
                arr[y+dy][x+dx] |= 1;
            }
            else
            {
                arr[y][x] |= 2;
                arr[y+dy][x+dx] |= 2;
            }

            y += dy;
            x += dx;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == 1)
            {
                cout << "-";
            }
            else if(arr[i][j] == 2)
            {
                cout << "|";
            }
            else if(arr[i][j] == 3)
            {
                cout << "+";
            }
            else
            {
                cout << ".";
            }
        }
        cout << "\n";
    }
}