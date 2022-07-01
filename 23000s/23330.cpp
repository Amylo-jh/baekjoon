#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <long long> num;
    num.reserve(500000);
    long long count;
    cin >> count;
    long long orig_count = count;

    long long total_distance = 0;
    long long after_sum = 0;
    long long before_sum = 0;

    for(int i = 0; i < count; i++)
    {
        long long n;
        cin >> n;
        after_sum += n;
        num.push_back(n);
    }

    sort(num.begin(), num.end());

    for(long long i = 0; i < orig_count; i++)
    {
        total_distance += after_sum - (num[i] * count) + (num[i] * i) - before_sum;
        after_sum -= num[i];
        before_sum += num[i];
        count--;
    }

    cout << total_distance;
}