#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> arr(26);
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        arr[str[0] - 'a']++;
    }

    bool flag = false;
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] >= 5)
        {
            flag = true;
            cout << char('a'+i);
        }
    }

    if(!flag)
    {
        cout << "PREDAJA";
    }
}