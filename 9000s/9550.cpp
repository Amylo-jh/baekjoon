#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n, k;
        cin >> n >> k;

        int counter = 0;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;

            counter += temp / k;
        }

        cout << counter << "\n";
    }
}