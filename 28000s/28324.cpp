#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector <long long> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long total_speed = 0;
    long long curr_speed = 1;
    for(int i = n-1; i >= 0; i--)
    {
        curr_speed = min(curr_speed, arr[i]);
        total_speed += curr_speed;
        curr_speed++;
    }

    cout << total_speed;
}