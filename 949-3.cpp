#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    
    vector <int> alcohol (n+1);
    for(int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        alcohol[i] += temp;
        if(i + l <= n)
        {
            alcohol[i+l] -= temp;
        }
    }

    int hour = 0;
    for(int i = 1; i <= n; i++)
    {
        alcohol[i] += alcohol[i-1];
        if(129 <= alcohol[i] && alcohol[i] <= 138)
        {
            hour++;
        }
    }

    cout << hour;    
}