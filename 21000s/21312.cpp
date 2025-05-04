#include <iostream>

using namespace std;

int main()
{   
    int arr[3];
    int answer = 1;
    bool flag = false;
    for(int i = 0; i < 3; i++)
    {
        cin >> arr[i];
        if(arr[i] % 2)
        {
            answer *= arr[i];
            flag = true;
        }
    }

    if(!flag)
    {
        answer = arr[0] * arr[1] * arr[2];
    }

    cout << answer;
}