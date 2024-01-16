#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while(cin >> n)
    {
        unsigned long long num = 1;
        int counter = 1;
        while(num % n != 0)
        {
            num *= 10;
            num++;
            counter++;
            num %= n;
        }

        cout << counter << "\n";
    }
}