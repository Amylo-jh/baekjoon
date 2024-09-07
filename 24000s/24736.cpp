#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> score = {6, 3, 2, 1, 2};
    int a = 0;
    int b = 0;

    for(int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        a += score[i] * x;
    }
    for(int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        b += score[i] * x;
    }

    cout << a << " " << b;
}