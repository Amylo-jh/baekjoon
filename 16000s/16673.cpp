#include <iostream>

using namespace std;

int main()
{
    int c, k, p;
    cin >> c >> k >> p;

    long long wine = 0;
    for(int i = 1; i <= c; i++)
    {
        wine += k*i + p*i*i;
    }

    cout << wine;
}