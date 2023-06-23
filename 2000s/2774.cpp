#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        vector <int> num(10);
        int n;
        cin >> n;

        while(n)
        {
            int remainder = n % 10;
            num[remainder]++;
            n /= 10;
        }

        int count = 0;
        for(int i = 0; i < 10; i++)
        {
            if(num[i])
            {
                count++;
            }
        }

        cout << count << "\n";
    }
}