#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;

    vector <int> food(n);
    vector <int> able_to_eat(n, c);
    vector <int> eat_count(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> food[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(able_to_eat[j] - food[i] >= 0)
            {
                able_to_eat[j] -= food[i];
                eat_count[j]++;
            }
        }
    }

    int max_eat = 0;
    for(int i = 0; i < n; i++)
    {
        max_eat = max(max_eat, eat_count[i]);
    }

    cout << max_eat;
}