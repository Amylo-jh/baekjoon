#include <iostream>
#include <string>

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
        long long n, m;
        cin >> n >> m;

        if(n < 3 || m < 3)
        {
            cout << "First";
        }
        else
        {
            if(n % 2 && m % 2)
            {
                cout << "First";
            }
            else if(n % 2 || m % 2)
            {
                cout << "Second";
            }
            else
            {
                cout << "Second";
            }
        }
        cout << "\n";
    }
}