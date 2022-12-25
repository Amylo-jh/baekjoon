#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        int sum = 0;
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            sum += temp;
        }

        cout << sum << "\n";
    }
}