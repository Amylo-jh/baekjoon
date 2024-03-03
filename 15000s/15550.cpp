#include <iostream>

using namespace std;

int main()
{
    // cout << "int 2147483647" << "\n";
    // cout << "float 2147483647" << "\n";
    // cout << "double 2147483648" << "\n";

    int a = 2100000000;
    float b = 2100000000;
    double c = 2100000001;

    if (a == b && b == c && c != a) {
        cout << "true" << '\n';
    } else {
        cout << "false" << '\n';
    }
    return 0;
}