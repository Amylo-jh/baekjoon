#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <int> arr(5);
    int n;
    string str;
    cin >> n >> str;

    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'u')
        {
            arr[0]++;
        }
        else if(str[i] == 'o')
        {
            arr[1]++;
        }
        else if(str[i] == 's')
        {
            arr[2]++;
        }
        else if(str[i] == 'p')
        {
            arr[3]++;
        }
        else if(str[i] == 'c')
        {
            arr[4]++;
        }
    }

    int result = INT32_MAX;
    for(int i = 0; i < 5; i++)
    {
        result = min(result, arr[i]);
    }

    cout << result;
}