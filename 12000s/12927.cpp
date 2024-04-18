#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    vector <bool> arr(n);
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == 'Y')
        {
            arr[i] = true;
        }
        else
        {
            arr[i] = false;
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i])
        {
            count++;
            for(int j = i; j < n; j += i + 1)
            {
                arr[j] = !arr[j];
            }
        }
    }

    cout << count;
}