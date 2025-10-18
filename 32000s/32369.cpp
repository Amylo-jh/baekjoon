#include <iostream>

using namespace std;

int main()
{
    int n, a, b, good = 1, bad = 1;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)
    {
        good += a;
        bad += b;

        if(good < bad)
        {
            swap(good, bad);
        }
        else if(good == bad)
        {
            bad--;
        }
    }
    cout << good << " " << bad;
}