#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> expected_rank;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        expected_rank.push_back(temp);
    }

    sort(expected_rank.begin(), expected_rank.end());

    long long total_dissatisfaction = 0;

    for(int i = 1; i <= n; i++)
    {
        int dissatisfaction = i - expected_rank[i-1];

        if(dissatisfaction < 0)
        {
            dissatisfaction = dissatisfaction * -1;
        }

        total_dissatisfaction = total_dissatisfaction + dissatisfaction;
    }

    cout << total_dissatisfaction;
}