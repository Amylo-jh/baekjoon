#include <iostream>

using namespace std;

int main()
{
    bool arr[10001];

    for(int i = 1; i <= 10000; i++)
    {
        arr[i] = true;
    }

    for(int i = 1; i <= 10000; i++)
    {
        int temp = i;
        int sum = i;

        while(temp)
        {
            sum += temp % 10;
            temp = temp / 10;
        }

        if(sum > 10000)
        {
            continue;
        }
        
        arr[sum] = false;
    }

    for(int i = 1; i <= 10000; i++)
    {
        if(arr[i])
        {
            cout << i << endl;
        }
    }
}