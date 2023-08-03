#include <iostream>
#include <vector>

using namespace std;

vector <long long> arr;
vector <long long> seg;

long long sum(int start, int end, int left, int right, int node)
{
    if(right < start || end < left)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return seg[node];
    }

    int mid = (start + end) / 2;
    return sum(start, mid, left, right, node*2) + sum(mid+1, end, left, right, node*2+1);
}

void update(int start, int end, int node, int index, long long diff)
{
    if(start <= index && index <= end)
    {       
        seg[node] += diff;
        if(start != end)
        {
            int mid = (start + end) / 2;
            update(start, mid, node*2, index, diff);
            update(mid+1, end, node*2+1, index, diff);    
        }
    }
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

    for(int i = 0; i < m; i++)
    {
        long long f, a, b;
        cin >> f >> a >> b;
        if(f == 0)
        {
            cout << sum(0, n-1, min(a-1, b-1), max(a-1, b-1), 1) << '\n';
        }
        else
        {
            a--;
            long long diff = b - arr[a];
            update(0, n-1, 1, a, diff);
            arr[a] = b;
        }
    }
}