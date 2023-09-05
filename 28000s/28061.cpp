#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int result = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        temp -= (n-i);
        result = max(result, temp);
    }

    cout << result;
}