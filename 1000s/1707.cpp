#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;

    while(tc--)
    {
        int v, e;
        cin >> v >> e;
        vector <vector <int>> edge(v);
        vector <int> vertex(v);
        vector <bool> visited(v);

        for(int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        stack <int> dfs_stack;
        for(int i = 1; i < v; i++)
        {
            dfs_stack.push(i);
        }
        dfs_stack.push(0);
        vertex[0] = 1;

        bool flag = true;
        while(!dfs_stack.empty())
        {
            int curr_node = dfs_stack.top();
            int curr_color = vertex[curr_node];
            int next_color = !curr_color;
            dfs_stack.pop();
            
            if(visited[curr_node])
            {
                continue;
            }
            visited[curr_node] = true;
            
            for(int i : edge[curr_node])
            {
                if(!visited[i])
                {
                    dfs_stack.push(i);
                    vertex[i] = next_color;
                }
                else
                {
                    if(vertex[i] == curr_color)
                    {
                        flag = false;
                        dfs_stack = {};
                        break;
                    }
                }
            }
        }

        // for(int i = 0; i < v; i++)
        // {
        //     if(!visited[i])
        //     {
        //         flag = false;
        //     }
        // }

        if(flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}