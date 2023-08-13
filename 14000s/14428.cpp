#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> arr;
vector <pair <int, int>> seg;
// value, index

pair <int, int> init(int start, int end, int node)
{
    if(start == end)
    {
        return seg[node] = make_pair(arr[start], start);
    }

    int mid = (start + end) / 2;
    pair <int, int> left_return = init(start, mid, node*2);
    pair <int, int> right_return = init(mid+1, end, node*2+1);

    return seg[node] = min(left_return, right_return);
}

pair <int, int> update(int start, int end, int pos, int value, int node)
{
    if(pos < start || end < pos)
    {
        return seg[node];
    }
    if(start == end)
    {
        return seg[node] = {value, pos};
    }

    int mid = (start + end) / 2;
    pair <int, int> left_return = update(start, mid, pos, value, node*2);
    pair <int, int> right_return = update(mid+1, end, pos, value, node*2+1);

    return seg[node] = min(left_return, right_return);
}

pair <int, int> get(int start, int end, int left, int right, int node)
{
    if(right < start || end < left)
    {
        return {INT32_MAX, INT32_MAX};
    }
    if(left <= start && end <= right)
    {
        return seg[node];
    }

    int mid = (start + end) / 2;
    pair <int, int> left_return = get(start, mid, left, right, node*2);
    pair <int, int> right_return = get(mid+1, end, left, right, node*2+1);

    return min(left_return, right_return);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    arr.resize(n);
    seg.resize(n*4);
    seg.assign(n*4, {INT32_MAX, INT32_MAX});

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    init(0, n-1, 1);

    int q;
    cin >> q;
    for(int p = 0; p < q; p++)
    {
        int q, i, j;
        cin >> q >> i >> j;
        if(q == 1)
        {
            i--;
            update(0, n-1, i, j, 1);
            arr[i] = j;
        }
        else
        {
            i--;
            j--;
            cout << get(0, n-1, i, j, 1).second + 1 << "\n";
        }
    }
}