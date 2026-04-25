#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pos
{
    long long x, y, idx;

    bool operator<(const pos &other) const
    {
        if (x != other.x)
        {
            return x < other.x;
        }
        return y < other.y;
    }
};

pos base_point;

long long ccw(pos a, pos b, pos c)
{
    long long result = a.x*b.y + b.x*c.y + c.x*a.y - (b.x*a.y + c.x*b.y + a.x*c.y);
    if(result > 0)
    {
        return 1;
    }
    else if(result < 0)
    {
        return -1;
    }
    return 0;
}

long long dist(pos a, pos b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool comp(pos a, pos b)
{
    long long cw = ccw(base_point, a, b);
    if (cw)
    {
        return cw > 0;
    }
    return dist(base_point, a) < dist(base_point, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<pos> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].x >> arr[i].y;
            arr[i].idx = i;
        }
        sort(arr.begin(), arr.end());
        base_point = arr[0];
        sort(arr.begin()+1, arr.end(), comp);

        int t = n-1;
        for(int i = n-1; i >= 1; i--)
        {
            if(ccw(base_point, arr[t], arr[t-1]) == 0)
            {
                t--;
            }
            else
            {
                break;
            }
        }
        reverse(arr.begin()+t, arr.end());

        for (int i = 0; i < n; i++)
        {
            cout << arr[i].idx << " ";
        }
        cout << "\n";
    }
}