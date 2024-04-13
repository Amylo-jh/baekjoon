#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <long long> arr(10001);
    arr[2] = 1;
    arr[4] = 2;

    for(int i = 6; i <= 10000; i += 2)
    {
        long long temp = 0;
        temp += arr[i-2] * 2;
        for(int j = 2; j < i - 2; j += 2)
        {
            temp += arr[j] * arr[(i-2) - j];
            temp %= 987654321;
        }
        arr[i] = temp;
    }

    int n;
    cin >> n;
    cout << arr[n];
}