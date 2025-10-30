#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = 0;
    int sum = 0;
    int commit = 0;
    int idx = 0;
    for(int i = 1; i <= 365; i++)
    {
        sum += commit;
        if(arr[idx] == i)
        {
            commit++;
            idx++;
            if(idx == n)
            {
                count++;
                break;
            }
        }
        if(sum+commit >= 20)
        {
            sum = 0;
            commit = 0;
            count++;
        }
    }

    cout << count;
}