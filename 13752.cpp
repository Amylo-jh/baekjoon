#include <iostream>

using namespace std;

int main()
{
    int testcase;

    cin >> testcase;

    for(int i = 0; i < testcase; i++)
    {
        int j = 0;
        cin >> j;

        for(int k = 0; k < j; k++)
        {
            cout << "=";
        }
        cout << endl;
    }
}