#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int time = 0;
    int task = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        time += temp;

        if(time > k)
        {
            break;
        }
        task++;
    }

    cout << task;
}