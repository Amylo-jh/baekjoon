#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <bool> arr(10);

    for(int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;
        arr[n] = !arr[n];
    }

    for(int i = 0; i < 10; i++)
    {
        if(arr[i])
        {
            cout << i;
            break;
        }
    }
}