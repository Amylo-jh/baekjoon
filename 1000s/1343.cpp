#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <bool> arr;
int n;

int count(int pos)
{
    int counter = 0;
    while(pos < n && arr[pos])
    {
        counter++;
        pos++;
    }

    return counter;
}

int main()
{
    string str;
    cin >> str;
    n = str.length();
    arr.resize(n);

    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'X')
        {
            arr[i] = true;
        }
    }

    string resultstr;
    for(int i = 0; i < n; i++)
    {
        int length = count(i);
        if(length % 2)
        {
            cout << "-1";
            return 0;
        }
        else if(length == 0)
        {
            resultstr += ".";
        }
        else
        {
            if(length >= 4)
            {
                resultstr += "AAAA";
                i += 3;
            }
            else
            {
                resultstr += "BB";
                i++;
            }
        }

    }
    cout << resultstr;
}