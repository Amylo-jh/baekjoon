#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long sum = 0, n, tmp;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        sum += tmp;
    }

    sum -= n*(n-1)/2;
    cout << sum;
}