#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 0, m;
    string answer, temp;

    for(int i = 0; i < 7; i++)
    {
        cin >> temp >> m;
        if(m > n)
        {
            n = m;
            answer = temp;
        }
    }

    cout << answer;
}