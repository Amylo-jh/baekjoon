#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> array;
    int n;
    cin >> n;

    int remainder;
    while(n > 0)
    {
        remainder = n % 10;
        n = n / 10;
        array.push_back(remainder);
    }

    sort(array.begin(),array.end());

    for(int i = array.size(); i > 0; i--)
    {
        cout << array[i-1];
    }
}