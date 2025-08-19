#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while(1)
    {
        cin >> str;
        if(str == "00e0")
        {
            break;
        }
        int num = 0;
        num += str[0] - '0';
        num *= 10;
        num += str[1] - '0';
        for(int i = 0; i < str[3] - '0'; i++)
        {
            num *= 10;
        }

        int two = 1;
        while(num >= two*2)
        {
            two = two << 1;
        }
        int remain = num - two;
        if(remain == 0)
        {
            cout << "1\n";
            continue;
        }
        else
        {
            cout << 2 * remain + 1 << "\n";
        }
    }
}