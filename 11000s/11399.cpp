#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> wait_time;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        wait_time.push_back(temp);
    }

    sort(wait_time.begin(), wait_time.end());

    int sum = 0;
    int total_wait_time = 0;

    for(int i = 0; i < n; i++)
    {
        sum = sum + wait_time[i];
        total_wait_time = total_wait_time + sum;
    }

    cout << total_wait_time;
}