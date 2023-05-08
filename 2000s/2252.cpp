#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector <vector <int>> student(n+1);
    vector <int> ref(n+1);
    queue <int> dag_queue;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        student[a].push_back(b);
        ref[b]++;
    }

    for(int i = 1; i <= n; i++)
    {
        if(ref[i] == 0)
        {
            dag_queue.push(i);
        }
    }

    while(!dag_queue.empty())
    {
        int curr_node = dag_queue.front();
        cout << curr_node << " ";
        dag_queue.pop();

        for(int i = 0; i < student[curr_node].size(); i++)
        {
            ref[student[curr_node][i]]--;
            if(ref[student[curr_node][i]] == 0)
            {
                dag_queue.push(student[curr_node][i]);
            }
        }
    }
}