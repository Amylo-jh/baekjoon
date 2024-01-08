#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> diff;

    int curr_pos = 0;
    int start = 0;
    cin >> curr_pos;
    start = curr_pos;
    for(int i = 1; i < n; i++)
    {
        int temp;
        cin >> temp;
        diff.push_back(temp-curr_pos);
        curr_pos = temp;
    }
    
    int min_dist = diff[0];
    for(int i = 1; i < diff.size(); i++)
    {
        min_dist = gcd(min_dist, diff[i]);
    }

    int count = 0;
    for(int i = 0; i < diff.size(); i++)
    {
        count += (diff[i] / min_dist) - 1;
    }

    cout << count;
}