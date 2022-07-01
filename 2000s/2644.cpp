#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct person
{
    set <int> connection;
};

int main()
{
    vector <person> persons;
    vector <bool> visited;
    int num;
    cin >> num;

    for(int i = 0; i <= num; i++)
    {
        person tmp;
        persons.push_back(tmp);
        visited.push_back(false);
    }

    int query_a;
    int query_b;
    cin >> query_a >> query_b;

    int con;
    cin >> con;

    for(int i = 0; i < con; i++)
    {
        int a, b;
        cin >> a >> b;

        persons[a].connection.insert(b);
        persons[b].connection.insert(a);
    }

    queue <int> bfs;
    queue <int> bfs_next;
    
    bfs.push(query_a);
    bool is_found = false;
    int length = 0;

    while(bfs.empty() == false)
    {
        while(bfs.empty() == false)
        {
            visited[bfs.front()] = true;

            int next_search = bfs.front();
            if(next_search == query_b)
            {
                is_found = true;
                break;
            }

            for(int q : persons[next_search].connection)
            {
                if(visited[q])
                {
                    continue;
                }
                else
                {
                    bfs_next.push(q);
                }
            }

            bfs.pop();
        }
        
        if(is_found)
        {
            break;
        }

        bfs = bfs_next;
        bfs_next = {};
        length++;
    }

    if(is_found)
    {
        cout << length;
    }
    else
    {
        cout << -1;
    }
}