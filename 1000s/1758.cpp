#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> tip(n);
    for(int i = 0; i < n; i++)
    {
        cin >> tip[i];
    }
    sort(tip.begin(), tip.end(), greater<>());

    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        int temp = tip[i] - i;
        if(temp > 0)
        {
            sum += temp;
        }
    }

    cout << sum;
}