#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int prev_total = 1;
    int curr_total = 1;
    int new_total = 1;

    for(int i = 1; i < n; i++)
    {
        new_total = (curr_total + prev_total) % 15746;
        prev_total = curr_total % 15746;
        curr_total = new_total % 15746;;
    }

    cout << new_total;
}