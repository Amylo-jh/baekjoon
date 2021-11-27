#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int total;
    int num[10] = {0};

    cin >> a >> b >> c;

    total = a * b * c;

    int temp;
    while(total > 0)
    {
        temp = total % 10;
        total = total / 10;
        num[temp]++;
    }

    for(int i = 0; i < 10; i++)
    {
        cout << num[i] << endl;
    }
}