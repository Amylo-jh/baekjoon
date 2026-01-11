#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> arr(4);
    vector <int> diff(3);
    for(int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }
    for(int i = 1; i < 4; i++)
    {
        diff[i-1] = arr[i]-arr[i-1];
    }
    if(!diff[0] && !diff[1] && !diff[2])
    {
        cout << "Fish At Constant Depth";
    }
    else if(diff[0] > 0 && diff[1] > 0 && diff[2] > 0)
    {
        cout << "Fish Rising";
    }
    else if(diff[0] < 0 && diff[1] < 0 && diff[2] < 0)
    {
        cout << "Fish Diving";
    }
    else
    {
        cout << "No Fish";
    }
}