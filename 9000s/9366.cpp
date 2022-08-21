#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 1; q <= tc; q++)
    {
        int a[3];
        int max_line = 0;
        int sum = 0;
        for(int i = 0; i < 3; i++)
        {
            cin >> a[i];
            max_line = max(max_line, a[i]);
            sum += a[i];
        }
        sum -= max_line;

        cout << "Case #" << q << ": ";
        if(sum <= max_line)
        {
            cout << "invalid!" << endl;
        }
        else
        {
            if(a[0] == a[1] && a[1] == a[2] && a[2] == a[0])
            {
                cout << "equilateral" << endl;
            }
            else if(a[0] == a[1] || a[1] == a[2] || a[2] == a[0])
            {
                cout << "isosceles" << endl;
            }
            else
            {
                cout << "scalene" << endl;
            }
        }
    }
}