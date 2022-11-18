#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <queue <int>> trees;
vector <bool> tree_info;

int bfs(int k)
{
    k++;
    int count = 0;
    queue <int> bfs_queue;
    queue <int> bfs_queue2;
    bfs_queue.push(0);

    while(k)
    {
        if(bfs_queue.empty())
        {
            break;
        }

        int target = bfs_queue.front();
        bfs_queue.pop();

        if(tree_info[target])
        {
            count++;
        }

        while (!trees[target].empty())
        {
            bfs_queue2.push(trees[target].front());
            trees[target].pop();
        }
        
        if(bfs_queue.empty())
        {
            bfs_queue = bfs_queue2;
            bfs_queue2 = {};
            k--;
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    trees.resize(n);
    tree_info.resize(n);

    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        trees[a].push(b);
    }
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        tree_info[i] = temp;
    }

    int count = bfs(k);

    cout << count;
}