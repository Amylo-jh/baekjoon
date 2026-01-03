#include <iostream>
#include <stack>

using namespace std;

int main()
{
    long long n, m, count = 0, tmp = 1;
    stack <long long> arr;
    cin >> n >> m;
    while(n >= tmp)
    {
        if(n & tmp)
        {
            arr.push(tmp);
            count++;
        }
        tmp *= 2;
    }

    if(count < m)
    {
        cout << -1;
        return 0;
    }
    for(int i = 1; i < m; i++)
    {
        n -= arr.top();
        arr.pop();
        cout << n << " ";
    }
    cout << 0;
}