#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <int> a;
    vector <int> b;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum = sum + a[i] * b[n-i-1];
    }

    cout << sum;
}