#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_gcd(int a, int b)
{
    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while(b)
    {
        int n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    int max_dividor = arr[1] - arr[0];
    for(int i = 2; i < n; i++)
    {
        max_dividor = get_gcd(max_dividor, arr[i] - arr[i-1]);
    }

    vector <int> result;
    result.push_back(max_dividor);
    for(int i = 1; i*2 <= max_dividor; i++)
    {
        if(max_dividor % i == 0)
        {
            result.push_back(i);

            if(max_dividor / i != i)
            {
                result.push_back(i);
            }
        }
    }
    sort(result.begin(), result.end());

    int prev_value = 0;
    for(int i = 0; i < result.size(); i++)
    {
        if(result[i] != 1 && result[i] != prev_value)
        {
            cout << result[i] << " ";
            prev_value = result[i];
        }
    }   
}