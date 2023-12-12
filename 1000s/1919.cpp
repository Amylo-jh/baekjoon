#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <int> arr(26);
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.length(); i++)
    {
        arr[a[i] - 'a']++;
    }
    for(int i = 0; i < b.length(); i++)
    {
        arr[b[i] - 'a']--;
    }
    int sum = 0;
    for(int i : arr)
    {
        sum += abs(i);
    }
    cout << sum;
}