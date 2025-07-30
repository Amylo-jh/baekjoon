#include <iostream>

using namespace std;

int main()
{
    int n, year = 2024, month = 0;
    cin >> n;
    month += n*7;
    year += (month-1)/12;
    month = (month%12) + 1;
    cout << year << " " << month;
}