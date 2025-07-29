#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int lo = 1, hi = n, mid = (lo+hi)/2;
    int result;
    while(lo <= hi)
    {
        cout << "? " << mid << "\n";
        cin >> result;

        if(result == -1)
        {
            lo = mid+1;
        }
        else if(result == 1)
        {
            hi = mid-1;
        }
        else if(result == 0)
        {
            cout << "= " << mid;
            break;
        }
        mid = (lo+hi)/2;
    }
}