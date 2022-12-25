#include <iostream>

using namespace std;

int main()
{
    int max_val = 0;
    int x = 0;
    int y = 0;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            int temp;
            cin >> temp;
            if(max_val < temp)
            {
                max_val = temp;
                x = i;
                y = j;
            }
        }
    }

    cout << max_val << "\n";
    cout << x+1 << " " << y+1;
}