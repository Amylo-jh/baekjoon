#include <iostream>

using namespace std;

int main()
{
    while(1)
    {
        int n;
        cin >> n;

        if(n == 0)
        {
            break;
        }

        int answer = 0;
        while(n)
        {
            answer += n*n;
            n--;
        }

        cout << answer << '\n';
    }
}