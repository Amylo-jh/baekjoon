#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n;
    vector <bool> arr(n+1, false);
    for(int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        if(str == "W")
        {
            arr[i] = true;
        }
    }
    cin >> m >> k;
    vector <bool> assist(m, true);
    for(int i = 0; i < m; i++)
    {
        int tmp;
        for(int j = 0; j < k; j++)
        {
            cin >> tmp;
            assist[i] = assist[i] & arr[tmp];
        }
    }
    bool answer = false;
    for(int i = 0; i < m; i++)
    {
        answer = answer | assist[i];
    }

    if(answer)
    {
        cout << "W";
    }
    else
    {
        cout << "P";
    }
}