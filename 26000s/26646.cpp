#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> mountain(n);
    for(int i = 0; i < n; i++)
    {
        cin >> mountain[i];
    }

    long long cost = 0;

    for(int i = 0; i < n-1; i++)
    {
        int a = mountain[i] - mountain[i+1];
        int b = mountain[i] + mountain[i+1];
        if(a < 0)
        {
            a *= -1;
        }

        cost += a*a + b*b;
    }

    cout << cost;
}