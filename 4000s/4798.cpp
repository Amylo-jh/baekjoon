#include <iostream>

using namespace std;

int main()
{
    int counter = 0;
    while(1)
    {
        counter++;
        int l, p, v;
        cin >> l >> p >> v;

        if(l + p + v == 0)
        {
            break;
        }

        int max_day = v / p * l + min(l, v%p);
        cout << "Case " << counter << ": " << max_day << "\n";
    }
}