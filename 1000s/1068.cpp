#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int parent = -1;
    vector <int> child = {};
    bool is_dead = false;
};

int main()
{
    int n;
    cin >> n;
    
    vector <node> graph(n);

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        graph[i].parent = temp;
        graph[temp].child.push_back(i);
    }

    int temp;    
    vector <int> temp_vec;

    cin >> temp;

    graph[temp].is_dead = true;
    int parent_of_dead = graph[temp].parent;
    for(int i : graph[parent_of_dead].child)
    {
        if(i != temp)
        {
            temp_vec.push_back(i);
        }
    }
    graph[parent_of_dead].child = temp_vec;
    
    queue <int> dead_queue;
    dead_queue.push(temp);
    while(!dead_queue.empty())
    {
        int curr_node = dead_queue.front();
        dead_queue.pop();

        for(int i : graph[curr_node].child)
        {
            graph[i].is_dead = true;
            dead_queue.push(i);
        }
    }

    int leap_node = 0;
    for(int i = 0; i < n; i++)
    {
        if(!graph[i].is_dead && graph[i].child.empty())
        {
            leap_node++;
        }
    }

    cout << leap_node;
}