#include <iostream>

using namespace std;

int main()
{
    int k;
    int a = 1;
    int b = 0;

    cin >> k;

    for(int i = 0; i < k; i++)
    {
        int prev_a = a;
        int prev_b = b;

        a = prev_b;
        b = prev_a + prev_b;
    }

    cout << a << " " << b;
}