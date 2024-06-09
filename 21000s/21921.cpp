#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max_value = 0;
    int count = 0;
    int day = 0;
    for(int i = 0; i < x; i++)
    {
        count += arr[i];
    }

    max_value = count;
    day = 1;
    for(int i = x; i < n; i++)
    {
        count += arr[i] - arr[i-x];
        if(count > max_value)
        {
            max_value = count;
            day = 1;
        }
        else if(count == max_value)
        {
            day++;
        }
    }

    if(max_value == 0)
    {
        cout << "SAD\n";
        return 0;
    }

    cout << max_value << '\n';
    cout << day << '\n';
}