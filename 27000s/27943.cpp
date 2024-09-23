#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long n;
    string gaji;
    cin >> n;

    long long gaji_lo = n/2+1, gaji_hi = n/2+1;

    cout << "? " << n/2+1 << endl;
    cin >> gaji;

    long long lo = 1;
    long long hi = n/2;
    while(lo <= hi)
    {
        long long mid = (lo+hi)/2;
        cout << "? " << mid << endl;

        string candidate;
        cin >> candidate;

        if(candidate == gaji)
        {
            hi = mid-1;
            gaji_lo = mid;
        }
        else
        {
            lo = mid+1;
        }
    }

    lo = n/2+1;
    hi = n;

    while(lo <= hi)
    {
        long long mid = (lo+hi)/2;
        cout << "? " << mid << endl;

        string candidate;
        cin >> candidate;

        if(candidate == gaji)
        {
            lo = mid+1;
            gaji_hi = mid;
        }
        else
        {
            hi = mid-1;
        }
    }

    cout << "! " << gaji_lo << " " << gaji_hi << endl;
}