#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        string str;
        int remain_date;
        cin >> str;
        str = str.substr(2, str.length() - 2);
        remain_date = stoi(str);
        if(remain_date <= 90)
        {
            count++;
        }
    }

    cout << count;
}