#include <iostream>
#include <vector>

using namespace std;

vector <long long> arr;
vector <long long> seg;

long long init(int start, int end, int node)
{
    if(start == end)
    {
        return seg[node] = arr[start];
    }

    int mid = (start + end) / 2;
    
    long long left_result = init(start, mid, node*2);
    long long right_result = init(mid+1, end, node*2+1);
    seg[node] = left_result + right_result;
    return seg[node];
}

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
    long long left_result = sum(start, mid, left, right, node*2);
    long long right_result = sum(mid+1, end, left, right, node*2+1);
    return left_result + right_result;
}

void update(int start, int end, int node, int pos, long long diff)
{
    if(pos < start || end < pos)
    {
        return;
    }

    seg[node] += diff;
    if(start != end)
    {
        int mid = (start + end) / 2;
        update(start, mid, node*2, pos, diff);
        update(mid+1, end, node*2+1, pos, diff);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    arr.resize(n);
    seg.resize(4*n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    init(0, n-1, 1);

    for(int i = 0; i < q; i++)
    {
        int start, end, pos;
        long long value, diff;
        cin >> start >> end >> pos >> value;
        start--;
        end--;
        pos--;

        if(start > end)
        {
            int temp = start;
            start = end;
            end = temp;
        }

        diff = value - arr[pos];

        cout << sum(0, n-1, start, end, 1) << "\n";
        update(0, n-1, 1, pos, diff);
        arr[pos] = value;
    }
}