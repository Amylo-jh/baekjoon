#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int counter = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i % arr[j] == 0)
            {
                counter++;
                break;
            }
        }
    }

    cout << counter;
}