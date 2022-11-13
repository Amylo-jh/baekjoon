#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <int> trees (n);
    for(int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }
    sort(trees.begin(), trees.end(), greater<>());

    int day = 1;
    int remain_day = 0;
    for(int i = 0; i < n; i++)
    {
        if(remain_day < trees[i])
        {
            day += trees[i] - remain_day;
            remain_day = trees[i];
        }
        remain_day--;
    }
    day++;

    cout << day;
}