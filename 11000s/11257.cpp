#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int num, s, i, t;
        cin >> num >> s >> i >> t;
        bool flag = true;

        if(s < 11 || i < 8 || t < 12)
        {
            flag = false;
        }
        if(s + i + t < 55)
        {
            flag = false;
        }

        cout << num << " " << s+i+t << " ";
        if(flag)
        {
            cout << "PASS\n";
        }
        else
        {
            cout << "FAIL\n";
        }
    }
}