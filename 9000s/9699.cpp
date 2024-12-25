#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int i = 1; i <= tc; i++)
    {
        int max_value = 0;
        for(int j = 0; j < 5; j++)
        {
            int value;
            cin >> value;
            max_value = max(max_value, value);
        }
        cout << "Case #" << i << ": " << max_value << "\n";
    }
}