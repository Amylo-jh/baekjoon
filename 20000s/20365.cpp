#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, b = 0, r = 0, idx = 0;
    string str;
    vector <int> arr;
    cin >> n >> str;
    
    if(str[0] == 'B')
    {
        arr.push_back(0);
        b++;
    }
    else
    {
        arr.push_back(1);
        r++;
    }

    for(int i = 1; i < str.length(); i++)
    {
        if(str[i] == 'B' && arr[idx] == 1)
        {
            arr.push_back(0);
            b++;
            idx++;
        }
        else if(str[i] == 'R' && arr[idx] == 0)
        {
            arr.push_back(1);
            r++;
            idx++;
        }
    }
    cout << min(b, r)+1;
}