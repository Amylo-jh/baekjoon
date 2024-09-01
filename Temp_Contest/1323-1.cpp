#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
string str;

int main()
{
    cin >> n >> str;

    vector <int> p_arr;
    vector <int> c_arr;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'P')
        {
            p_arr.push_back(i);
        }
        else if(str[i] == 'C')
        {
            c_arr.push_back(i);
        }
    }

    for(int i = 0; i < min(p_arr.size(), c_arr.size()); i++)
    {
        str[p_arr[i]] = 'C';
        str[c_arr[i]] = 'P';
    }

    cout << str;
}