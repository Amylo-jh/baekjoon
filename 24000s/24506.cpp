#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int answer = 1;
    for(int i = 0; i < 4; i++)
    {
        if(a[i] != b[i])
        {
            answer *= 2;
        }
    }
    cout << answer;
}