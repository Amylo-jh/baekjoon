#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while(true)
    {
        int num;
        cin >> num;

        if(num == 0)
        {
            break;
        }

        cout << num << " is ";

        if(num % n)
        {
            cout << "NOT ";
        }
        cout << "a multiple of " << n << "." << endl;
    }
}