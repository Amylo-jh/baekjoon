#include <iostream>

using namespace std;

int main()
{
    int money;
    cin >> money;

    int tax = money * 0.78;
    int notax = money - (money * 0.2 * 0.22);

    cout << tax << endl;
    cout << notax << endl;
}