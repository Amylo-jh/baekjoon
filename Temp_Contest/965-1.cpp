#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <pair <long long, long long>> primes(31);
    primes[2] = {2,1};
    primes[3] = {3,2};
    primes[4] = {5,6};
    primes[5] = {5,6};
    primes[6] = {7,30};
    primes[7] = {7,150};
    primes[8] = {199,210};
    primes[9] = {199,210};
    primes[10] = {199,210};
    primes[11] = {110437,13860};
    primes[12] = {110437,13860};
    primes[13] = {4943,60060};
    primes[14] = {31385539,420420};
    primes[15] = {115453391,4144140};
    primes[16] = {53297929,9699690};
    primes[17] = {3430751869,87297000};
    primes[18] = {4808316343,717770000};
    primes[19] = {8297644387,4180500000};
    primes[20] = {214861583621,18800000000};
    primes[21] = {5749146449311,26000000000};
    primes[22] = {};

    

    long long value = primes[n].first;
    for(int j = 0; j < n; j++)
    {
        //cout << value << " ";
        value += primes[n].second;
    }
    cout << "\n";
}