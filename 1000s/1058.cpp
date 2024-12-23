#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector <vector <int>> dist(n, vector <int> (n, 1e9));
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < n; j++)
        {
            if(str[j] == 'Y')
            {
                dist[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < n; k++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j || i == k || j == k)
                {
                    continue;
                } 
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int max_friends = 0;
    for(int i = 0; i < n; i++)
    {
        int friends = 0;
        for(int j = 0; j < n; j++)
        {
            if(dist[i][j] <= 2)
            {
                friends++;
            }
        }
        max_friends = max(max_friends, friends);
    }

    cout << max_friends;
}