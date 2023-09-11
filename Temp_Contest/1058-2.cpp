#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int i = 1; i <= tc; i++)
    {
        int n;
        cin >> n;

        cout << "Case #" << i << ": ";
        if(n > 4500)
        {
            cout << "Round 1";
        }
        else if(n > 1000)
        {
            cout << "Round 2";
        }
        else if(n > 25)
        {
            cout << "Round 3";
        }
        else
        {
            cout << "World Finals";
        }
        cout << "\n";
    }
}