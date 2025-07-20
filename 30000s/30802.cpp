#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t, p;
    vector <int> arr(6);
    cin >> n;
    for(int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }
    cin >> t >> p;

    int ta = 0;
    for(int i = 0; i < 6; i++)
    {
        ta += arr[i] / t;
        if(arr[i] % t)
        {
            ta++;
        }
    }

    cout << ta << "\n" << n/p << " " << n%p;
}