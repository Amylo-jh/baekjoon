#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector <double> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    double avg1, avg2;
    for(int i = k; i < n-k; i++)
    {
        avg1 += arr[i];
    }
    avg2 = avg1;
    avg1 /= n-2*k;

    avg2 += k*arr[k];
    avg2 += k*arr[n-k-1];
    avg2 /= n;

    avg1 += 1e-9;
    avg2 += 1e-9;

    cout << fixed;
    cout.precision(2);
    cout << avg1 << "\n" << avg2;
}