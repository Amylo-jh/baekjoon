#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> arr1(n+1);
    vector <int> arr2(n+1);
    for(int i = 1; i <= n; i++)
    {
        arr1[i] = i;
        arr2[i] = i;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        int counter = b;
        for(int i = a; i <= b; i++)
        {
            arr2[i] = arr1[counter];
            counter--;
        }
        arr1 = arr2;
    }

    for(int i = 1; i <= n; i++)
    {
        cout << arr1[i] << " ";
    }
}