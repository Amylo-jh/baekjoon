#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n;
        cout << "Pairs for " << n << ": ";

        for(int i = 1; i < n; i++)
        {
            if(i < n-i)
            {
                if(i != 1)
                {
                    cout << ", ";
                }
                cout << i << " " << n-i;
            }
        }
        cout << '\n';
    }
}