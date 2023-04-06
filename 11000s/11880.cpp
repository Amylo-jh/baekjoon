#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    
    while(tc--)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        cout << min(min((a*a + (b+c)*(b+c)), (b*b + (a+c)*(a+c))), (c*c + (a+b)*(a+b)));
        cout << "\n";
    }
}