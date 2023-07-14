#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> seg_max;
vector <int> seg_min;
vector <int> arr;

int seg_max_init(int start, int end, int node)
{
    if(start == end)
    {
        return seg_max[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return seg_max[node] = max(seg_max_init(start, mid, node*2), seg_max_init(mid+1, end, node*2+1));
}

int seg_min_init(int start, int end, int node)
{
    if(start == end)
    {
        return seg_min[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return seg_min[node] = min(seg_min_init(start, mid, node*2), seg_min_init(mid+1, end, node*2+1));
}

int find_max(int start, int end, int node, int left, int right)
{
    if(right < start || left > end)
    {
        return INT32_MIN;
    }
    if(left <= start && end <= right)
    {
        return seg_max[node];
    }

    int mid = (start + end) / 2;
    return max(find_max(start, mid, node*2, left, right), find_max(mid+1, end, node*2+1, left, right));
}

int find_min(int start, int end, int node, int left, int right)
{
    if(right < start || left > end)
    {
        return INT32_MAX;
    }
    if(left <= start && end <= right)
    {
        return seg_min[node];
    }

    int mid = (start + end) / 2;
    return min(find_min(start, mid, node*2, left, right), find_min(mid+1, end, node*2+1, left, right));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    arr.resize(n);
    int seg_size = (1 << ((int)ceil(log2(n))+1));
    seg_max.resize(seg_size);
    seg_min.resize(seg_size);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    seg_max_init(0, n-1, 1);
    seg_min_init(0, n-1, 1);

    for(int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        start--;
        end--;

        int max_value = find_max(0, n-1, 1, start, end);
        int min_value = find_min(0, n-1, 1, start, end);

        cout << min_value << " " << max_value << "\n";
    }
}