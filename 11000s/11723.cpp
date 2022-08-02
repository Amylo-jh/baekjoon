#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int query;
    cin >> query;

    bool arr[21] = {false};
    for(int q = 0; q < query; q++)
    {
        string str;
        int n;

        cin >> str;

        if(str == "add")
        {
            cin >> n;
            arr[n] = true;
        }
        else if(str == "remove")
        {
            cin >> n;
            arr[n] = false;
        }
        else if(str == "check")
        {
            cin >> n;
            if(arr[n])
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if(str == "toggle")
        {
            cin >> n;
            arr[n] = !arr[n];
        }
        else if(str == "all")
        {
            for(int i = 1; i <= 20; i++)
            {
                arr[i] = true;
            }
        }
        else if(str == "empty")
        {
            for(int i = 1; i <= 20; i++)
            {
                arr[i] = false;
            }
        }
    }
}