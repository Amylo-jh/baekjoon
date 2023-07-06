#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <long long> segtree;
vector <long long> arr;
    
long long seg_init(int start, int end, int node)
{
    if(start == end)
    {
        return segtree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return segtree[node] = seg_init(start, mid, node*2) + seg_init(mid+1, end, node*2+1);
}

void update(int start, int end, int node, int index, long long diff)
{
    if(index < start || end < index)
    {
        return;
    }

    segtree[node] += diff;

    if(start <= index && index <= end)
    {
        if(start == end)
        {
            return;
        }
        else
        {
            int mid = (start + end) / 2;
            update(start, mid, node*2, index, diff);
            update(mid+1, end, node*2+1, index, diff);
        }
    }
}

long long sum(int start, int end, int node, int left, int right)
{
    if(right < start || left > end)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return segtree[node];
    }

    int mid = (start + end) / 2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    //int seg_size = n*4;
    int seg_size =  (1 << ((int)ceil(log2(n)) + 1));
    segtree.resize(seg_size);
    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    seg_init(0, n-1, 1);

    for(int i = 0; i < m+k; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if(a == 1) // 수 변경
        {
            b--;
            long long diff = c - arr[b];
            update(0, n-1, 1, b, diff);
            arr[b] = c;
        }
        else // 구간합 출력
        {
            b--;
            c--;
            cout << sum(0, n-1, 1, b, c) << "\n";
        }
    }

}