#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    bool flag = false;
    for(int i = 1; i <= n; i++)
    {
        if(flag)
        {
            count++;
            flag = false;
        }

        string str = to_string(i);
        if(str.find("50") != std::string::npos)
        {
            flag = true;
        }

        count++;
    }

    cout << count;
}