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
    int sum = 0;
    cin >> n;

    vector <int> num(n);

    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
        sum += num[i];
    }
    sort(num.begin(), num.end());

    long long value = 0;
    for(int i = 0; i < n-1; i++)
    {
        sum -= num[i];
        value += num[i] * sum;
    }

    cout << value;
}