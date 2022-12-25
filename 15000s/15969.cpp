#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int min_happy = INT32_MAX;
    int max_happy = 0;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        min_happy = min(min_happy, temp);
        max_happy = max(max_happy, temp);
    }

    cout << max_happy - min_happy;
}