#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <int> arr(n);
    vector <int> counting(3);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] > 1)
        {
            arr[i] = 2;
        }

        counting[arr[i]]++;
    }

    long long sum = 0;
    for(int i = 0; i < n-1; i++)
    {
        counting[arr[i]]--;

        if(arr[i] == 0)
        {
            sum += counting[0] + (counting[1] * 2) + counting[2];
        }
        else if(arr[i] == 1)
        {
            sum += (counting[0] * 2);
        }
        else if(arr[i] == 2)
        {
            sum += counting[0];
        }
    }

    cout << sum;
}