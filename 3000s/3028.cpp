#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<bool> arr(4, false);
    arr[1] = true;
    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++)
    {
        bool temp = false;
        if(str[i] == 'A')
        {
            temp = arr[1];
            arr[1] = arr[2];
            arr[2] = temp;
        }
        else if(str[i] == 'B')
        {
            temp = arr[2];
            arr[2] = arr[3];
            arr[3] = temp;
        }
        else if(str[i] == 'C')
        {
            temp = arr[1];
            arr[1] = arr[3];
            arr[3] = temp;
        }
    }

    for(int i = 1; i < 4; i++)
    {
        if(arr[i])
        {
            cout << i;
            break;
        }
    }
}