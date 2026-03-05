#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string password;
    bool flag = true;
    cin >> n >> password;
    while(n--)
    {
        string a, b;
        cin >> a >> b;
        int count = 0;
        if (password.length() != a.length())
        {
            if(b == "ALLOWED")
            {
                flag = false;
                break;
            }
            continue;
        }
        for (int i = 0; i < password.length(); i++)
        {
            if (password[i] != a[i])
            {
                count++;
            }
        }
        if (count <= 1)
        {
            if (b == "DENIED")
            {
                flag = false;
                break;
            }
        }
        if (count > 1)
        {
            if (b == "ALLOWED")
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        cout << "SYSTEM SECURE";
    }
    else
    {
        cout << "INTEGRITY OVERFLOW";
    }
}