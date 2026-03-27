#include <iostream>

using namespace std;

int main()
{
    int a, b, c, total;
    cin >> a >> b >> c >> total;
    for (int i = 0; i * a <= total; i++)
    {
        for (int j = 0; j * b + i * a <= total; j++)
        {
            if ((total - i * a - j * b) % c == 0)
            {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;
}