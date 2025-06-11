#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    a = "SciComLove";
    cin >> b;
    int count = 0;
    for(int i = 0; i < 10; i++)
    {
        if(a[i] != b[i])
        {
            count++;
        }
    }

    cout << count;
}