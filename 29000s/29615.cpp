#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <bool> arr(n+1);
    vector <int> waiting(n);
    for(int i = 0; i < n; i++)
    {
        cin >> waiting[i];
    }
    int friends = 0;
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        arr[temp] = true;
        friends++;
    }

    int counter = 0;
    for(int i = 0; i < friends; i++)
    {
        if(!arr[waiting[i]])
        {
            counter++;
        }
    }

    cout << counter;
}