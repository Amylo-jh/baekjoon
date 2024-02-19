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
    vector <int> arr(n+1);
    vector <int> result(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int counter = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == i)
        {
            result[i] = n;
            counter++;
        }
        else
        {
            result[i] = arr[i];
        }
    }
    if(arr[n] == n)
    {
        counter++;
        result[n] = 1;
    }
    else
    {
        result[n] = arr[n];
    }

    cout << counter << "\n";
    for(int i = 1; i <= n; i++)
    {
        cout << result[i] << " ";
    }
}