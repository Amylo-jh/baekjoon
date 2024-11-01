#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool comp(pair <int, string> a, pair <int, string> b)
{
    if(a.first == b.first)
    {
        return false;
    }
    return a.first > b.first;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector <pair <int, string>> vote(n+1);

    vote[n] = {0, "Invalid"};
    for(int i = 0; i < n; i++)
    {
        cin >> vote[i].second;
    }
    for(int i = 0; i < m; i++)
    {
        int count = 0;
        string ballot;
        cin >> ballot;

        for(int j = 0; j < n; j++)
        {
            if(ballot[j] == 'X')
            {
                count++;
            }
        }
        if(count > 1 || count == 0)
        {
            vote[n].first++;
            continue;
        }
        for(int j = 0; j < n; j++)
        {
            if(ballot[j] == 'X')
            {
                vote[j].first++;
            }
        }
    }

    stable_sort(vote.begin(), vote.end()-1, comp);

    cout << fixed;
    cout.precision(2);
    for(int i = 0; i < n; i++)
    {
        cout << vote[i].second << " ";
        double percentage = (double)vote[i].first/m*10000;
        percentage = round(percentage);
        percentage /= 100;
        cout << percentage << "%\n";
    }
    cout << vote[n].second << " ";
    double percentage = (double)vote[n].first/m*10000;
    percentage = round(percentage);
    percentage /= 100;
    cout << percentage << "%";
}