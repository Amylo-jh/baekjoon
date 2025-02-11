#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        long long max_price = 0;
        string answer;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            long long price;
            string name;
            cin >> price >> name;
            if(price > max_price)
            {
                max_price = price;
                answer = name;
            }
        }
        cout << answer << "\n";
    }
}