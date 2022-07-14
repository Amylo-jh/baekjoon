#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int s;
    vector <int> diff;

    cin >> n >> s;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        temp = temp - s;
        if(temp < 0)
        {
            temp = -1 * temp;
        }

        diff.push_back(temp);
    }

    int max_d = diff[0];

    for(int i = 1; i < n; i++)
    {
        max_d = gcd(max_d, diff[i]);
    }

    cout << max_d;
}