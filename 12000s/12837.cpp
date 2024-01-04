#include <iostream>
#include <vector>

using namespace std;

vector <long long> seg;
int n;

void update(int start, int end, int node, int index, int diff)
{
    if(start <= index && index <= end)
    {
        seg[node] += diff;

        if(start == end)
        {
            return;
        }

        int mid = (start + end) / 2;
        update(start, mid, node*2, index, diff);
        update(mid+1, end, node*2+1, index, diff);
    }
}

long long sum (int start, int end, int node, int left, int right)
{
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return seg[node];
    }

    int mid = (start + end) / 2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;
    cin >> n >> q;

    seg.resize(n*4);

    while(q--)
    {
        int query;
        cin >> query;
        if(query == 1)
        {
            int p, delta;
            cin >> p >> delta;
            update(1, n, 1, p, delta);
        }
        else
        {
            int left, right;
            cin >> left >> right;
            cout << sum(1, n, 1, left, right) << "\n";
        }
    }
}