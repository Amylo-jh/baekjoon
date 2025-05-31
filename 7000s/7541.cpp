#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    vector <int> arr = {9, 3, 7};
    for(int t = 1; t <= tc; t++)
    {
        string str;
        cin >> str;

        int sum = 0;
        int mul = 0;
        int counter = 0;
        int pos = 0;
        for(int i = str.length()-1; i >= 0; i--)
        {
            if(str[i] == '?')
            {
                mul = arr[counter];
                pos = i;
            }
            else
            {
                sum += (str[i] - '0') * arr[counter];
            }

            counter = (counter+1)%3;
        }

        for(int i = 0; i < 10; i++)
        {
            if((i * mul + sum) % 10 == 0)
            {
                str[pos] = '0' + i;
                break;
            }
        }

        cout << "Scenario #" << t << ":\n";
        cout << str << "\n\n";
    }
}