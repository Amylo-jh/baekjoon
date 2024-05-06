#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <string> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    string str;
    cin >> str;

    int result = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == str)
        {
            result++;
        }
    }

    cout << result << endl;
}
