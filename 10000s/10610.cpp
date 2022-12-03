#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string str;
    vector <int> count(10);
    cin >> str;

    int sum = 0;
    bool flag = false;
    for(int i = 0; i < str.length(); i++)
    {
        int num = str[i] - 48;
        count[num]++;
        sum += num;
    }

    if(sum % 3 == 0 && count[0])
    {
        for(int i = 9; i >= 0; i--)
        {
            while(count[i]--)
            {
                cout << i;
            }
        }
    }
    else
    {
        cout << -1;
    }
}