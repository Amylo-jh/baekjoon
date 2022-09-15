#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;
    
    for(int q = 0; q < tc; q++)
    {
        int a, b;
        cin >> a >> b;
        
        while(a != b)
        {
            if(a > b)
            {
                a /= 2;
            }
            else
            {
                b /= 2;
            }
        }

        cout << a * 10 << "\n";
    }
}