#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, tmp, box = 0;
    vector <int> arr(5);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr[tmp]++;
    }
    box += arr[4];
    box += arr[3];
    arr[1] = max(0, arr[1] - arr[3]);
    box += arr[2] / 2;
    arr[2] = arr[2] % 2;
    if(arr[2])
    {
        box++;
        arr[1] = max(0, arr[1] - 2);
    }
    box += arr[1] / 4 + !!(arr[1] % 4);

    cout << box;
}