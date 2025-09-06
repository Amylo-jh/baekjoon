#include <iostream>

using namespace std;

int main()
{
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(abs(x-a)*abs(x-a) + abs(y-b)*abs(y-b) > k*k)
        {
            count++;
        }
    }
    cout << count;
}