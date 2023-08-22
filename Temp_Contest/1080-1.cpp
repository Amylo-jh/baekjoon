#include <iostream>
#include <vector>
#include <string>

using namespace std;

void get_path(int x, int y)
{
    while(x || y)
    {
        if(x == 1 && y > 0)
        {
            cout << "Z";
            x--;
            y--;
        }
        else if(y > 0 && abs(x) <= y && x > -y)
        {
            cout << "A";
            x--;
        }
        else if(x < 0 && y > x)
        {
            cout << "X";
            y--;
        }
        else if(y < 0 && x < abs(y))
        {
            cout << "D";
            x++;
        }
        else if(x > 0 && y < x)
        {
            cout << "W";
            y++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        get_path(x, y);
        cout << "\n";
    }
}