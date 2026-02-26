#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string a, b;
        vector<int> arr(26);
        cin >> a >> b;
        for (int i = 0; i < a.length(); i++)
        {
            arr[a[i] - 'a']++;
        }
        for (int i = 0; i < b.length(); i++)
        {
            arr[b[i] - 'a']--;
        }
        bool flag = true;
        for (int i = 0; i < 26; i++)
        {
            if (arr[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "Possible\n";
        }
        else
        {
            cout << "Impossible\n";
        }
    }
}