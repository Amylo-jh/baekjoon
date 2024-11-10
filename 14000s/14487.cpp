#include <iostream>

using namespace std;

int main()
{
    int n;
    int total = 0;
    int max_value = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        total += temp;
        max_value = max(max_value, temp);
    }

    cout << total - max_value;
}