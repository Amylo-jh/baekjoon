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

        int ae = 0, ao = 0, be = 0, bo = 0;
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if(temp % 2)
            {
                ao++;
            }
            else
            {
                ae++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if(temp % 2)
            {
                bo++;
            }
            else
            {
                be++;
            }
        }

        int answer = abs(be - ao);
        cout << answer << "\n";
    }
}