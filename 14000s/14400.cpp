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
    vector <int> x;
    vector <int> y;
    int middle_x;
    int middle_y;
    long long total_distance = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp_x, temp_y;
        cin >> temp_x >> temp_y;
        x.push_back(temp_x);
        y.push_back(temp_y);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    middle_x = x[n/2];
    middle_y = y[n/2];

    for(int i = 0; i < n; i++)
    {
        int distance_x = abs(middle_x - x[i]);
        int distance_y = abs(middle_y - y[i]);

        total_distance += distance_x + distance_y;
    }

    cout << total_distance;
}