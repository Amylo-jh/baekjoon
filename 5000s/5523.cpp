#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a_s = 0, b_s = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a > b)
        {
            a_s++;
        }
        if(a < b)
        {
            b_s++;
        }
    }

    cout << a_s << " " << b_s;
}