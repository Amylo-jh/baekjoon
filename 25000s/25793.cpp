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
        int r, c;
        long long a, b;
        cin >> r >> c;
        
        a = min(r, c);
        b = abs(r - c);

        long long white = 0;
        long long black = 0;

        white = (a*(a+1)*(2*a + 1) / 3) + a*(a+1)*(b-1) + a*(1-b);
        black = white - a;

        cout << white << " " << black << "\n";
    }
}