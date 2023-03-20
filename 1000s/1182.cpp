#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    vector <int> num(n);
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int counter = 0;
    for(int bitmask = 1; bitmask < pow(2, n); bitmask++)
    {
        int sum = 0;
        int index = 0;
        for(int mask = 1; mask <= bitmask;)
        {
            if(bitmask & mask)
            {
                sum += num[index];
            }
            index++;
            mask *= 2;
        }

        if(sum == s)
        {
            counter++;
        }
    }

    cout << counter;
}