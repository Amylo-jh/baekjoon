#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    n /= a;

    vector <int> plant(n, k);
    int day = 0;
    while(1)
    {
        if(plant[day%n] - day == 0)
        {
            cout << day;
            return 0;
        }
        plant[day%n] += b;
        day++;
    }
}