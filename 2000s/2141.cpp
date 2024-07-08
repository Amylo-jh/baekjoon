// = 2285

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

    long long population = 0;
    vector <pair <int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        population += arr[i].second;
    }
    sort(arr.begin(), arr.end());

    long long pop_sum = 0;
    for(int i = 0; i < n; i++)
    {
        pop_sum += arr[i].second;
        if(pop_sum >= (population + 1) / 2)
        {
            cout << arr[i].first;
            break;
        }
    }
}