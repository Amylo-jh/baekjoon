#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int min_x, max_x, min_y, max_y;
    max_x = max_y = INT32_MIN;
    min_x = min_y = INT32_MAX;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        max_x = max(max_x, x);
        min_x = min(min_x, x);
        max_y = max(max_y, y);
        min_y = min(min_y, y);
    }

    cout << (max_x - min_x) * (max_y - min_y);
}