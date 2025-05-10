#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    vector <bool> arr(26);
    for(int i = 0; i < a.size(); i++)
    {
        arr[a[i] - 'a'] = true;
    }
    for(int i = 0; i < b.size(); i++)
    {
        if(!arr[b[i] - 'a'])
        {
            cout << b[i];
        }
    }
}