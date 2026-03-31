#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n, sector, total_size = 0;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> sector;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            total_size += sector * (arr[i] / sector) + !!(arr[i] % sector) * sector;
        }
    }
    cout << total_size;
}