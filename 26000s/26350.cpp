#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int k = 0; k < tc; k++)
    {
        int n;
        cin >> n;
        vector <int> arr(n);

        int prev;
        cin >> arr[0];

        bool flag = false;
        for(int i = 1; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i-1]*2 > arr[i])
            {
                flag = true;
            }
        }

        cout << "Denominations: ";
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        if(flag)
        {
            cout << "Bad coin denominations!\n";
        }
        else
        {
            cout << "Good coin denominations!\n";
        }
        
        if(k+1 != tc)
        {
            cout << "\n";
        }
    }
}