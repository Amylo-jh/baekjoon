#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    m--;
    
    long long cases = 1;

    for(int i = 0; i < n-1; i++)
    {
        cases = cases * m;
        m--;
        cases = cases / (i+1);
    }

    cout << cases;
}