#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long a = 1, temp;
    for(int i = 0; i < 3; i++)
    {
        cin >> temp;
        a *= temp;
    }

    vector <int> arr(10);
    while(a)
    {
        arr[a%10]++;
        a /= 10;
    }

    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << "\n";
    }
}