#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <bool> arr(10000001, true);
    int k;
    cin >> k;

    int cnt = 0;
    arr[0] = arr[1] = false;
    for(int i = 2; i <= 10000000; i++)
    {
        if(arr[i])
        {
            cnt++;
            if(cnt == k)
            {
                cout << i;
                return 0;
            }
            for(int j = i * 2; j <= 10000000; j += i)
            {
                arr[j] = false;
            }
        }
    }
}