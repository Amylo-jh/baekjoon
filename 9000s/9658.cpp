#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <bool> arr(n+5, true);
    arr[1] = arr[3] = false;
    for(int i = 4; i <= n; i++)
    {
        if(arr[i-1] && arr[i-3] && arr[i-4])
        {
            arr[i] = false;
        }
        else
        {
            arr[i] = true;
        }
    }

    if(arr[n])
    {
        cout << "SK";
    }
    else
    {
        cout << "CY";
    }
}