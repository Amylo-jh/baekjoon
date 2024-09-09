#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;

    if(t == 1)
    {
        long long a, b;
        cin >> a >> b;

        a = a + b;

        string str = "";

        // convert decimal to 25 lowercase base
        while(a > 0)
        {
            str += (char)('a' + a%26);
            a /= 26;
        }

        while(str.length() < 13)
        {
            str += 'a';
        }

        cout << str;
    }
    else
    {
        long long answer = 0;
        string str;
        cin >> str;

        for(int i = 12; i >= 0; i--)
        {
            answer *= 26;
            answer += (str[i] - 'a');
        }

        cout << answer;
    }
}