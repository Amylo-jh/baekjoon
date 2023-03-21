#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector <vector <char>> area;
int max_val = INT32_MIN;
int min_val = INT32_MAX;
int n;

void evaluate(vector <char> curr_vec)
{
    int result = curr_vec[0] - 48;
    for(int i = 1; i < curr_vec.size(); i = i + 2)
    {
        if(curr_vec[i] == '+')
        {
            result += curr_vec[i+1] - 48;
        }
        else if(curr_vec[i] == '-')
        {
            result -= curr_vec[i+1] - 48;
        }
        else if(curr_vec[i] == '*')
        {
            result *= curr_vec[i+1] - 48;
        }
    }

    min_val = min(min_val, result);
    max_val = max(max_val, result);
}

void dfs()
{
    stack <pair < pair<int, int>, vector<char> >> dfs_stack;
    vector <char> temp_vec;
    temp_vec.push_back(area[0][0]);
    dfs_stack.push({{0, 0}, temp_vec});

    int dy[2] = {0, 1};
    int dx[2] = {1, 0};

    while(!dfs_stack.empty())
    {
        int curr_y = dfs_stack.top().first.first;
        int curr_x = dfs_stack.top().first.second;
        vector <char> curr_vec = dfs_stack.top().second;
        dfs_stack.pop();

        if(curr_y == n-1 && curr_x == n-1)
        {
            evaluate(curr_vec);
            continue;
        }

        for(int i = 0; i < 2; i++)
        {
            int y = curr_y + dy[i];
            int x = curr_x + dx[i];

            if(0 <= y && y < n && 0 <= x && x < n)
            {
                vector <char> dfs_temp_vec = curr_vec;
                dfs_temp_vec.push_back(area[y][x]);
                dfs_stack.push({{y, x}, dfs_temp_vec});
            }
        }
    }
}

int main()
{
    cin >> n;

    area.resize(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            char temp_ch;
            cin >> temp_ch;
            area[i][j] = temp_ch;
        }
    }

    dfs();
    cout << max_val << " " << min_val;
}