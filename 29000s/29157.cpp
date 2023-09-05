#include <iostream>
#include <vector>

using namespace std;

// long long nCr(int x, int y)
// {
//     (x+y)!/x! * y!
// }

long long combination(int n, int r)
{
    if(n == r || r == 0) 
        return 1; 
    else 
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    long long total_minus = 0;
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        total_minus = combination(x+y, y) * combination((n-x+m-y), (n-x));
        // total_minus %= 1000000007;
        cout << total_minus;
    }

    cout << combination(n+m, m);
}