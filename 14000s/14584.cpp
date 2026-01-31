#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;
    vector <string> arr(26);
    for(int i = 0; i < 26; i++)
    {
        string newstr;
        for(char ch : str)
        {
            int tmp = ch;
            tmp += i;
            if('z' < tmp)
            {
                tmp -= 26;
            }
            newstr += tmp;
        }
        arr[i] = newstr;
    }

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < 26; j++)
        {
            if(arr[j].find(str) != arr[j].npos)
            {
                cout << arr[j];
                j = 26;
                i = n;
            }
        }
    }
}