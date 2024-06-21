#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int s, n;
    cin >> s >> n;

    vector <int> arr(s+1);
    vector <int> seat(n);
    for(int i = 0; i < n; i++)
    {
        cin >> seat[i];
        arr[seat[i]]++;
    }
    sort(seat.begin(), seat.end());

    int count = 0;

    int blank = 0;
    for(int i = seat[0]+1; i <= s; i++)
    {
        if(arr[i] == 0)
        {
            blank++;
        }
        else
        {
            count += (blank-1)/2;
            blank = 0;
        }
    }
    for(int i = 1; i <= seat[0]; i++)
    {
        if(arr[i] == 0)
        {
            blank++;
        }
        else
        {
            count += (blank-1)/2;
            blank = 0;
        }
    }

    cout << count;
}