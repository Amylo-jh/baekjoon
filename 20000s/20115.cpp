#include <iostream>

using namespace std;

int main()
{
    long long total_value = 0;
    long long max_value = 0;
    int n;
    
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        max_value = max(max_value, temp);
        total_value += temp;
    }
    total_value -= max_value;
    double val = double(total_value) / 2;
    
    cout << val + max_value;
}