#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool comp (string s1, string s2)
{
    string s12 = s1 + s2;
    string s21 = s2 + s1;
    return s12 > s21;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <string> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), comp);

    int index = 0;
    while(index < n && arr[index] == "0")
    {
        index++;
    }
    if(index == n)
    {
        cout << "0";
    }
    for(; index < n; index++)
    {
        cout << arr[index];
    }
}