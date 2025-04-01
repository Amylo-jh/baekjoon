#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <pair <double, double>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    int tc;
    cin >> tc;
    while(tc--)
    {
        int target;
        cin >> target;
        vector <int> point(target);
        for(int i = 0; i < target; i++)
        {
            cin >> point[i];
        }

        double dist = 0;
        for(int i = 0; i < target-1; i++)
        {
            double x1 = arr[point[i]].first;
            double y1 = arr[point[i]].second;
            double x2 = arr[point[i+1]].first;
            double y2 = arr[point[i+1]].second;
            
            dist += sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        }

        cout << fixed;
        cout.precision(0);
        cout << dist << "\n";
    }
}