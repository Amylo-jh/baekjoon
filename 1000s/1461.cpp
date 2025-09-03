#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    long long distance = 0;
    cin >> n >> m;
    vector <int> minus = {0};
    vector <int> plus = {0};
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(temp < 0)
        {
            minus.push_back(temp);
        }
        else
        {
            plus.push_back(temp);
        }
    }
    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end(), greater<>());
    for(int i = 0; i < minus.size(); i += m)
    {
        distance += -minus[i] * 2;
    }
    for(int i = 0; i < plus.size(); i += m)
    {
        distance += plus[i] * 2;
    }
    distance -= max(-minus[0], plus[0]);

    cout << distance;
}