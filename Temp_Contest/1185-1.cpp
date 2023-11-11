#include <iostream>
#include <vector>

using namespace std;

vector <int> arr;

int find_flower(int a, int b, int k)
{
    int counter = 0;
    for(int i = a; i <= b; i++)
    {
        if(arr[i] == k)
        {
            counter++;
        }
    }

    return counter;
}

int main()
{
    int n;
    cin >> n;
    arr.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    
    int q;
    cin >> q;
    while(q--)
    {
        int query, a, b, k;
        cin >> query;
        if(query == 1)
        {
            cin >> a >> b >> k;
            cout << find_flower(a, b, k) << "\n";
        }
        else
        {
            cin >> a >> b;
            for(int i = a; i <= b; i++)
            {
                arr[i] = 0;
            }
        }
    }
}