#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector <vector <int>> node;

int dfs(int n)
{
    int return_value = 0;
    
    if(node[n].empty())
    {
        return 0;
    }

    vector <int> sub_arr;
    for(int i = 0; i < node[n].size(); i++)
    {
        sub_arr.push_back(dfs(node[n][i]));
    }

    sort(sub_arr.begin(), sub_arr.end(), greater());

    for(int i = 0; i < sub_arr.size(); i++)
    {
        return_value = max(return_value, sub_arr[i] + i+1);
    }

    return return_value;
}

int main()
{
    int n;
    cin >> n;
    node.resize(n);    

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(temp == -1)
        {
            continue;
        }
        node[temp].push_back(i);
    }
    
    int time = dfs(0);

    cout << time;
}