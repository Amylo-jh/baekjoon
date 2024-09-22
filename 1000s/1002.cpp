#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double dist = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        int r = r1 + r2;

        if(dist == 0)
        {
            if(r1 == r2)
            {
                cout << -1;
            }
            else
            {
                cout << 0;
            }
        }
        else if(dist == r || dist == abs(r1-r2))
        {
            cout << 1;
        }
        else if(dist < r && dist > abs(r1-r2))
        {
            cout << 2;
        }
        else
        {
            cout << 0;
        }

        cout << "\n";
    }
}