#include <iostream>
#include <vector>

using namespace std;

int main()
{
    while(1)
    {
        vector <int> arr = {1};
        int n;
        cin >> n;

        if(n == -1)
        {
            break;
        }

        int sum = 1;
        for(int i = 2; i < n; i++)
        {
            if(n%i == 0)
            {
                arr.push_back(i);
                sum += i;
            }
        }

        if(sum == n)
        {
            cout << n << " = ";
            for(int i : arr)
            {
                if(i != 1)
                {
                    cout << " + ";
                }
                cout << i;
            }
        }
        else
        {
            cout << n << " is NOT perfect.";
        }
        cout << "\n";
    }
}