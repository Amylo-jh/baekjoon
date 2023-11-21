#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> arr;
vector <vector <int>> tree;
int n;

void find_tree(int depth, int start, int end)
{
    if(depth == n)
    {
        return;
    }
    
    int mid = (start + end) / 2;
    tree[depth].push_back(arr[mid]);
    find_tree(depth+1, start, mid-1);
    find_tree(depth+1, mid+1, end);
}

int main()
{
    cin >> n;
    int node = pow(2, n) - 1;
    arr.resize(node);
    tree.resize(n);

    for(int i = 0; i < node; i++)
    {
        cin >> arr[i];
    }

    find_tree(0, 0, node-1);

    for(int i = 0; i < n; i++)
    {
        for(int j : tree[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}