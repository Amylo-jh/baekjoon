#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n;
    vector <string> arr;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        if(str.length() == 3)
        {
            arr.push_back(str);
        }
    }
    sort(arr.begin(), arr.end());
    cout << arr[0];
}