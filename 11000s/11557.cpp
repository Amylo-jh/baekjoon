#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string max_str, str;
        int max_value = 0, value, n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> str >> value;
            if (value > max_value)
            {
                max_str = str;
                max_value = value;
            }
        }
        cout << max_str << "\n";
    }
}