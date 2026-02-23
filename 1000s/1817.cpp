#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, count = 0, box = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int curr;
        cin >> curr;
        if (curr > box)
        {
            count++;
            box = m-curr;
        }
        else
        {
            box -= curr;
        }
    }
    cout << count;
}