#include <iostream>
#include <vector>

using namespace std;

vector <int> seg;
vector <int> arr;

int init(int start, int end, int node)
{
    if(start == end)
    {
        return seg[node] = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        return seg[node] = min(init(start, mid, node*2), init(mid+1, end, node*2+1));
    }
}

int fetch(int start, int end, int left, int right, int node)
{
    if(left > end || right < start)
    {
        return INT32_MAX;
    }
    if(left <= start && end <= right)
    {
        return seg[node];
    }

    int mid = (start+end) / 2;
    return min(fetch(start, mid, left, right, node*2), fetch(mid+1, end, left, right, node*2+1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    arr.resize(n);
    seg.resize(n*4);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    init(0, n-1, 1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << fetch(0, n-1, a, b, 1) << "\n";
    }
}