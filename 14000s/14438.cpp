#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> arr;
vector <int> seg;

int init(int start, int end, int node)
{
    if(start == end)
    {
        return seg[node] = arr[start];
    }

    int mid = (start + end)/2;

    int left_value = init(start, mid, node*2);
    int right_value = init(mid+1, end, node*2+1);
    return seg[node] = min(left_value, right_value);
}

int update(int start, int end, int node, int index, int value)
{
    if(index < start || end < index)
    {
        return seg[node];
    }
    if(start == end)
    {
        return seg[node] = value;
    }

    int mid = (start + end) / 2;
    return seg[node] = min(update(start, mid, node*2, index, value), update(mid+1, end, node*2+1, index, value));
}

int get(int start, int end, int left, int right, int node)
{
    if(right < start || end < left)
    {
        return INT32_MAX;
    }
    if(left <= start && end <= right)
    {
        return seg[node];
    }

    int mid = (start + end) / 2;
    return min(get(start, mid, left, right, node*2), get(mid+1, end, left, right, node*2+1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    arr.resize(n);
    seg.resize(n*4);
    seg.assign(n*4, INT32_MAX);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    init(0, n-1, 1);

    int q;
    cin >> q;
    for(int k = 0; k < q; k++)
    {
        int query, i, j;
        cin >> query >> i >> j;

        if(query == 1)
        {
            update(0, n-1, 1, i-1, j);
            arr[i-1] = j;
        }
        else
        {
            cout << get(0, n-1, i-1, j-1, 1) << "\n";
        }
    }
}