#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> gram = {100, 50, 20, 10, 10, 5, 2, 1};
    int n;
    cin >> n;

    int a = 0;
    int b = 0;

    cin >> a >> b;

    for(int i = 0; i < n-2; i++)
    {
        int temp;
        cin >> temp;
        if(a < b)
        {
            a += temp;
        }
        else
        {
            b += temp;
        }
    }

    int diff = abs(a - b);
    int counter = 0;

    for(int i : gram)
    {
        counter += diff / i;
        diff %= i;
    }

    cout << counter;
}