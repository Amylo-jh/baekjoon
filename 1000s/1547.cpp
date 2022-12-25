#include <iostream>

using namespace std;

int main()
{
    int cup[4] = {0, 1, 2, 3};

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        int temp = cup[a];
        cup[a] = cup[b];
        cup[b] = temp;
    }

    for(int i = 1; i < 4; i++)
    {
        if(cup[i] == 1)
        {
            cout << i;
        }
    }
}