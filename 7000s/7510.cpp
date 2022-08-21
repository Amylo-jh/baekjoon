#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        int line[3];
        int max_line = 0;
        int other_line = 0;
        for(int i = 0; i < 3; i++)
        {
            cin >> line[i];
            other_line += line[i] * line[i];
            max_line = max(max_line, line[i]);
        }

        max_line = max_line*max_line;

        other_line -= max_line;

        cout << "Scenario #" << q+1 << ":" << "\n";
        if(other_line == max_line)
        {
            cout << "yes";
        }
        else
        {
            cout << "no";
        }
        cout << "\n\n";
    }
}