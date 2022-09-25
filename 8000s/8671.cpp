#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int value = INT32_MAX;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        value = min(value, temp);
    }

    cout << fixed;
    cout.precision(2);
    cout << double(value);
}