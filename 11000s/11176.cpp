#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n, e;
        cin >> e >> n;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if(temp > e)
            {
                count++;
            }
        }

        cout << count << "\n";
    }
}