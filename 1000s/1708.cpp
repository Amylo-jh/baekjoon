#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct pos {
    long long x, y;

    bool operator<(const pos& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;   
    }
};

vector<pos> arr;

long long ccw(pos a, pos b, pos c)
{
    return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

long long dist(pos a, pos b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool comp(pos a, pos b)
{
    long long cc = ccw(arr[0], a, b);
    if (cc)
    {
        return cc > 0;
    }
    else
    {
        return dist(arr[0], a) < dist(arr[0], b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr.begin(), arr.end());
    sort(arr.begin() + 1, arr.end(), comp);

    stack<pos> stk;
    stk.push(arr[0]);
    stk.push(arr[1]);
    for (int i = 2; i < n; i++)
    {
        while (stk.size() >= 2)
        {
            pos t2 = stk.top();
            stk.pop();
            pos t1 = stk.top();

            if (ccw(t1, t2, arr[i]) > 0)
            {
                stk.push(t2);
                break;
            }
        }
        stk.push(arr[i]);
    }
    cout << stk.size();
}