#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tcc;
    cin >> tcc;
    for(int tc = 1; tc <= tcc; tc++)
    {
        int n;
        cin >> n;
        vector <int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        while(n != 2)
        {
            vector <int> arr2;
            for(int i = 0; i < n/2; i++)
            {
                arr2.push_back(arr[i] + arr[n-i-1]);
            }
            if(n%2)
            {
                arr2.push_back(arr[n/2]*2);
            }
            n = n/2 + (n%2);
            swap(arr, arr2);
        }
        cout << "Case #" << tc << ": ";
        if(arr[0] > arr[1])
        {
            cout << "Alice\n"; 
        }
        else
        {
            cout << "Bob\n";
        }
    }
}