#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    vector <int> arr(3);
    cout << "Gnomes:\n";
    while(tc--)
    {
        for(int i = 0; i < 3; i++)
        {
            cin >> arr[i];
        }
        if((arr[0] - arr[1]) * (arr[1] - arr[2]) > 0)
        {
            cout << "Ordered\n";
        }
        else
        {
            cout << "Unordered\n";
        }
    }
}