#include <iostream>
#include <vector>

using namespace std;

vector <long long> tree, arr, seq;

long long sum(int node, int start, int end, int left, int right)
{
    if(left > end || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;
    long long v1 = sum(node*2, start, mid, left, right);
    long long v2 = sum(node*2+1, mid+1, end, left, right);
    return v1 + v2;
}

void update(int node, int start, int end, int idx, int diff)
{
    if(idx < start || idx > end)
    {
        return;
    }

    tree[node] += diff;

    if(start == end)
    {
        return;
    }

    int mid = (start + end) / 2;
    update(node*2, start, mid, idx, diff);
    update(node*2+1, mid+1, end, idx, diff);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    arr.resize(n+1);
    tree.resize(4*n + 4);
    seq.resize(1000001);
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        seq[temp] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = seq[temp];
    }

    long long answer = 0;
    for(int i = 1; i <= n; i++)
    {
        int temp = arr[i];
        answer += sum(1, 1, n, temp+1, n);
        update(1, 1, n, temp, 1);
    }

    cout << answer;
}