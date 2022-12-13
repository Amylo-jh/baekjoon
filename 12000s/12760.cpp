#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int>> cards;
vector <int> score;

int main()
{
    int n, m;
    cin >> n >> m;
    cards.resize(n);
    score.resize(n);

    for(int i = 0; i < n; i++)
    {
        cards[i].resize(m);
        for(int j = 0; j < m; j++)
        {
            cin >> cards[i][j];
        }
        sort(cards[i].begin(), cards[i].end(), greater<>());
    }

    int max_value;
    for(int i = 0; i < m; i++)
    {
        max_value = 0;
        for(int j = 0; j < n; j++)
        {
            max_value = max(max_value, cards[j][i]);
        }
        for(int j = 0; j < n; j++)
        {
            if(max_value == cards[j][i])
            {
                score[j]++;
            }
        }
    }

    int max_score = 0;
    for(int i = 0; i < n; i++)
    {
        max_score = max(max_score, score[i]);
    }
    for(int i = 0; i < n; i++)
    {
        if(score[i] == max_score)
        {
            cout << i+1 << " ";
        }
    }
}