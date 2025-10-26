#include <iostream>

using namespace std;

int main()
{
    int arr[4] = {5000, 500, 800, 1000};
    int tmp;
    while(cin >> tmp)
    {
        arr[0] -= arr[tmp];
    }
    cout << arr[0];
}