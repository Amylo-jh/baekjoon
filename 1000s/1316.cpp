#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        vector <int> arr(26);
        arr.assign(26, -1);

        bool flag = true;
        for(int j = 0; j < str.length(); j++)
        {
            char ch = str[j];
            ch -= 97;
            if(arr[ch] == -1 || arr[ch] == j-1)
            {
                arr[ch] = j;
            }
            else
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            count++;
        }
    }

    cout << count;
}