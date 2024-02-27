#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'P')
        {
            int start = max(0, i-k);
            int end = min(n-1, i+k);
            for(int j = start; j <= end; j++)
            {
                if(str[j] == 'H')
                {
                    counter++;
                    str[j] = 'O';
                    break;
                }
            }
        }
    }

    cout << counter;
}