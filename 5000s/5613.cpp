#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    while(1)
    {
        string tmp;
        long long num;
        cin >> tmp;

        if(tmp == "=")
        {
            cout << n;
            break;
        }
        else if(tmp == "+")
        {
            cin >> num;
            n += num;
        }
        else if(tmp == "-")
        {
            cin >> num;
            n -= num;
        }
        else if(tmp == "*")
        {
            cin >> num;
            n *= num;
        }
        else if(tmp == "/")
        {
            cin >> num;
            n /= num;
        }
    }
}