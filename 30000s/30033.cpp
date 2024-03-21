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

    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(temp >= arr[i])
        {
            counter++;
        }
    }

    cout << counter;
}