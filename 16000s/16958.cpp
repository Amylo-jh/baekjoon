#include <iostream>
#include <vector>

using namespace std;

struct city
{
    int x;
    int y;
    bool special = false;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int city_count;
    int teleport_time;
    cin >> city_count >> teleport_time;
    vector <city> cities(city_count);
    vector <vector <int>> graph(city_count);

    for(int i = 0; i < city_count; i++)
    {
        cin >> cities[i].special >> cities[i].x >> cities[i].y;
    }

    for(int i = 0; i < city_count; i++)
    {
        vector <int> temp_vec(city_count);
        for(int j = 0; j < city_count; j++)
        {
            int tp = INT32_MAX;
            int dx = cities[i].x - cities[j].x;
            int dy = cities[i].y - cities[j].y;
            if(dx < 0)
            {
                dx *= -1;
            }
            if(dy < 0)
            {
                dy *= -1;
            }
            if(cities[i].special && cities[j].special)
            {
                tp = teleport_time;
            }
            temp_vec[j] = min(dx + dy, tp);
        }
        graph[i] = temp_vec;
    }

    for(int k = 0; k < city_count; k++)
    {
        for(int i = 0; i < city_count; i++)
        {
            for(int j = 0; j < city_count; j++)
            {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << graph[a][b] << "\n";
    }
}