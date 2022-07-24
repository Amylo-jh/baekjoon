#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> players;
vector <bool> position;
int max_fit = 0;

void dfs(int index, int sum)
{
    if(index == 11)
    {
        max_fit = max(max_fit, sum);
        return;
    }
    else
    {
        for(int i = 0; i < 11; i++)
        {
            if(position[i] == false && players[index][i] != 0)
            {
                position[i] = true;
                dfs(index + 1, sum + players[index][i]);
                position[i] = false;
            }
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {        
        players.clear();
        position.clear();
        max_fit = 0;
        for(int i = 0; i < 11; i++)
        {
            vector <int> player(11);
            for(int j = 0; j < 11; j++)
            {
                cin >> player[j];
            }
            players.push_back(player);
            position.push_back(false);
        }

        dfs(0, 0);
        cout << max_fit << "\n";
    }
}