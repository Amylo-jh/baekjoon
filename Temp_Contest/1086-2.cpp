#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int arr[4] = {0};
    map <long double, int> slope;

    for(int i = 0; i < n; i++)
    {
        long double x, y;
        cin >> x >> y;

        if(x == 0 && y > 0)
        {
            arr[0] = 1;
            continue;
        }
        else if(x == 0 && y < 0)
        {
            arr[1] = 1;
            continue;
        }
        else if(y == 0 && x > 0)
        {
            arr[2] = 1;
            continue;
        }
        else if(y == 0 && x < 0)
        {
            arr[3] = 1;
            continue;
        }
        long double curr_slope = y/x;
        slope.insert({curr_slope, 1});
    }

    cout << slope.size() + arr[0]+arr[1]+arr[2]+arr[3];
}