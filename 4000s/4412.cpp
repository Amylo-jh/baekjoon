#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool compare_str(string str1, string str2)
{
    if(str1.size() != str2.size())
    {
        return false;
    }

    bool diff = false;
    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] != str2[i])
        {
            if(diff)
            {
                return false;
            }
            diff = true;
        }
    }

    return diff;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <vector <string>> arr(17);
    vector <vector <vector <int>>> graph(17);
    string s1, s2;
    int n = 0;
    while(1)
    {
        string s;
        getline(cin, s);

        if(s.empty())
        {
            break;
        }

        arr[s.size()].push_back(s);
        n++;
    }
    for(int i = 1; i <= 16; i++)
    {
        sort(arr[i].begin(), arr[i].end());
        graph[i].resize(arr[i].size());
    }

    for(int k = 1; k <= 16; k++)
    {
        int a_sz = arr[k].size();
        for(int i = 0; i < a_sz - 1; i++)
        {
            for(int j = i+1; j < a_sz; j++)
            {
                if(compare_str(arr[k][i], arr[k][j]))
                {
                    graph[k][i].push_back(j);
                    graph[k][j].push_back(i);
                }
            }
        }
    }

    bool is_run = false;
    while(cin >> s1 >> s2)
    {
        if(is_run)
        {
            cout << "\n\n";
        }
        else
        {
            is_run = true;
        }

        int idx1, idx2, size = s1.size();
        if(s1.size() != s2.size())
        {
            cout << "No solution.";
            continue;
        }
        idx1 = lower_bound(arr[size].begin(), arr[size].end(), s1) - arr[size].begin();
        idx2 = lower_bound(arr[size].begin(), arr[size].end(), s2) - arr[size].begin();

        if(arr[size][idx1] != s1 || arr[size][idx2] != s2)
        {
            cout << "No solution.";
            continue;
        }

        queue <int> bfs_queue;
        vector <bool> visited(arr[size].size(), false);
        vector <int> route(arr[size].size(), -1);
        bfs_queue.push(idx1);
        visited[idx1] = true;
        bool is_found = false;

        while(!bfs_queue.empty())
        {
            int curr_node = bfs_queue.front();
            bfs_queue.pop();

            for(int i = 0; i < graph[size][curr_node].size(); i++)
            {
                if(visited[graph[size][curr_node][i]])
                {
                    continue;
                }
                int next_node = graph[size][curr_node][i];
                bfs_queue.push(next_node);
                visited[next_node] = true;
                route[next_node] = curr_node;

                if(next_node == idx2)
                {
                    is_found = true;
                    vector <int> path;
                    while(route[curr_node] != -1)
                    {
                        path.push_back(curr_node);
                        curr_node = route[curr_node];
                    }
                    path.push_back(idx1);

                    for(int i = path.size()-1; i >= 0; i--)
                    {
                        cout << arr[size][path[i]] << '\n';
                    }
                    cout << arr[size][idx2];
                    
                    bfs_queue = queue <int>();
                    break;
                }
            }
        }
        
        if(!is_found)
        {
            cout << "No solution.";
        }
    }
}