#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n, m;
        cin >> n >> m;

        int counter = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if((i*i + j*j + m) % (i*j) == 0)
                {
                    counter++;
                }
            }
        }
        cout << counter << "\n";
    }
}