#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <string> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < arr[0].length(); i++)
    {
        bool flag = true;
        for(int j = 0; j < n; j++)
        {
            if(arr[0][i] != arr[j][i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout << arr[0][i];
        }
        else
        {
            cout << "?";
        }
    }
}