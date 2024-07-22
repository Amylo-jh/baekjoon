#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector <long long> temp_vec(n);
    stack <pair <long long, int>> front_stk;
    stack <pair <long long, int>> back_stk;
    for(int i = n-1; i >= 0; i--)
    {
        cin >> temp_vec[i];
    }
    for(int i = 0; i < n; i++)
    {
        back_stk.push({temp_vec[i], n-i});
    }

    while(n > 1)
    {
        long long curr_node = back_stk.top().first;
        int curr_index = back_stk.top().second;
        back_stk.pop();

        long long next_node = curr_node;
        if(!front_stk.empty() && curr_node >= front_stk.top().first)
        {
            next_node += front_stk.top().first;
            front_stk.pop();
            n--;
        }
        if(!back_stk.empty() && curr_node >= back_stk.top().first)
        {
            next_node += back_stk.top().first;
            back_stk.pop();
            n--;
        }

        front_stk.push({next_node, curr_index});

        if(back_stk.empty())
        {
            while(!front_stk.empty())
            {
                back_stk.push(front_stk.top());
                front_stk.pop();
            }
        }
    }

    cout << back_stk.top().first << "\n" << back_stk.top().second;
}