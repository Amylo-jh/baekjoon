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

    vector <int> rope(n);
    for(int i = 0; i < n; i++)
    {
        cin >> rope[i];
    }
    sort(rope.begin(), rope.end(), greater<>());
    
    int max_weight = 0;
    for(int i = 0; i < n; i++)
    {
        max_weight = max(max_weight, rope[i] * (i+1));
    }

    cout << max_weight;
}