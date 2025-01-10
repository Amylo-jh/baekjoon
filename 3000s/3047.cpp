#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector <int> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());

    string str;
    cin >> str;
    for(int i = 0; i < 3; i++)
    {
        cout << arr[str[i] - 'A'] << " ";
    }
}