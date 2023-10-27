#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long nn = n*n;
    
    long long total_num = 0;
    for(int i = 1; i < n; i++)
    {
        total_num += i;
    }

    total_num *= (n+1);
    cout << total_num;
}