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

    int nums[10001] = {0};

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums[temp]++;
    }

    for(int i = 0; i <= 10000; i++)
    {
        int temp = nums[i];

        for(int j = 0; j < temp; j++)
        {
            cout << i << "\n";
        }
    }
}