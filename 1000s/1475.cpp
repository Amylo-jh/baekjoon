#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> arr(10);
    int num;
    cin >> num;

    while(num)
    {
        int temp = num % 10;
        num /= 10;
        if(temp == 6)
        {
            arr[9]++;
            continue;
        }
        arr[temp]++;
    }

    if(arr[9] % 2)
    {
        arr[9]++;
    }
    arr[9] /= 2;

    int result = 0;
    for(int i = 0; i < 10; i++)
    {
        result = max(result, arr[i]);
    }

    cout << result;
}