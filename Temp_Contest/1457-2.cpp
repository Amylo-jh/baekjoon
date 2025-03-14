#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        long long tmp;
        cin >> tmp;
        sum += tmp -1;
    }

    if(sum >= m)
    {
        cout << "DIMI";
    }
    else
    {
        cout << "OUT";
    }
}