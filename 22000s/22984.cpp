#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <double> percentage(n);
    double total_percentage = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> percentage[i];
        total_percentage += percentage[i];
    }

    for(int i = 1; i < n; i++)
    {
        total_percentage += ((1-percentage[i-1]) * percentage[i]) + (percentage[i-1] * (1-percentage[i]));
    }

    cout << fixed;
    cout.precision(7);
    cout << total_percentage;
}