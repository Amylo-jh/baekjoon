#include <iostream>
#include <vector>

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
        int m;
        cin>>m;
        
        int a = 0, b = 0;
        for(int i = 2; i <= m; i *= 2)
        {
            a += m / i;
        }
        for(int j = 5; j <= m; j *= 5)
        {
            b += m / j;
        }
        
        cout << min(a,b) << "\n";    
    }
}