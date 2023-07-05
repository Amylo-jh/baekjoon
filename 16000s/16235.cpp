#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int>> feed;
vector <vector <int>> area;
// seq; age;
vector <vector <vector <int>>> tree;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    area.resize(n);
    feed.resize(n);
    tree.resize(n);
    for(int i = 0; i < n; i++)
    {
        area[i].resize(n);
        feed[i].resize(n);
        tree[i].resize(n);
        for(int j = 0; j < n; j++)
        {
            cin >> feed[i][j];
            area[i][j] = 5;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int x, y, age;
        cin >> x >> y >> age;
        x--;
        y--;
        tree[x][y].push_back(age);
    }

    int seq = 0;
    while(k--)
    {
        // spring, summer
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int feed_sum = 0;
                int count = 0;
                for(int o = 0; o < tree[i][j].size(); o++)
                {
                    if(area[i][j] >= tree[i][j][o])
                    {
                        area[i][j] -= tree[i][j][o];
                        tree[i][j][o]++;
                    }
                    else
                    {
                        //dead tree
                        feed_sum += tree[i][j][o]/2;
                        count++;
                    }
                }
                // summer
                area[i][j] += feed_sum;
                while(count--)
                {
                    tree[i][j].pop_back();
                }
            }
        }

        //fall
        int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int o = 0; o < tree[i][j].size(); o++)
                {
                    if(tree[i][j][o] % 5 == 0)
                    {
                        for(int q = 0; q < 8; q++)
                        {
                            int y = i + dy[q];
                            int x = j + dx[q];
                            if(0 <= y && y < n && 0 <= x && x < n)
                            {
                                tree[y][x].push_back(1);
                            }
                        }
                    }
                }
                
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                sort(tree[i][j].begin(), tree[i][j].end());
            }
        }

        //winter
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                area[i][j] += feed[i][j];
            }
        }
    }

    int total_trees = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            total_trees += tree[i][j].size();
        }
    }   

    cout << total_trees;
}