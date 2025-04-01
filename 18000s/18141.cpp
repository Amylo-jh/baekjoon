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

    bool flag = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(i == j || i == k || j == k)
                {
                    continue;
                }
                if(((arr[i] - arr[j]) % arr[k]) != 0)
                {
                    flag = false;
                    i = j = k = n;
                }
            }
        }
    }

    if(flag)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}