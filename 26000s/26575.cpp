#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        double dog;
        double eat, price;
        cin >> dog >> eat >> price;

        
        cout.precision(2);
        cout << fixed;
        cout << "$" << dog*eat*price << "\n";
    }
}