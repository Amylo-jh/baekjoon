#include <iostream>

using namespace std;

int main()
{
    int tmp1, tmp2;
    int total;

    cin >> tmp1 >> tmp2;
    total = tmp1 * tmp2;

    for(int i = 0; i < 5; i++)
    {
        cin >> tmp1;
        cout << tmp1 - total << " ";
    }
}