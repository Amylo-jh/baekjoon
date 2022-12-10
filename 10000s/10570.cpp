#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        vector <int> num(1001);
        int n;
        cin >> n;
        while(n--)
        {
            int i;
            cin >> i;
            num[i]++;
        }

        int selected = 0;
        int value = 0;
        for(int i = 1; i <= 1000; i++)
        {
            if(num[i] > value)
            {
                value = num[i];
                selected = i;
            }
        }

        cout << selected << "\n";
    }
}