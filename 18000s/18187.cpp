#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n+1);
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 7;

    int delta = 3;
    for(int i = 4; i <= n; i++)
    {
        arr[i] += arr[i-1] + delta;
        delta++;
        if(i % 3 == 0)
        {
            delta--;
        }
    }

    cout << arr[n];
}