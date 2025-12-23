#include <iostream>
#include <vector>

using namespace std;

int main()
{
    while(1)
    {
        int n, sum = 0;
        vector <int> arr;
        cin >> n;
        if(n == -1)
        {
            break;
        }
        for(int i = 1; i <= n/2; i++)
        {
            if(n % i == 0)
            {
                arr.push_back(i);
                sum += i;
            }
        }
        cout << n << " ";
        if(sum == n)
        {
            cout << "= ";
            int a_size = arr.size();
            for(int i = 0; i < a_size; i++)
            {
                cout << arr[i] << " ";
                if(i != a_size-1)
                {
                    cout << "+ ";
                }
            }
            cout << "\n";
        }
        else
        {
            cout << "is NOT perfect.\n";
        }
    }
}