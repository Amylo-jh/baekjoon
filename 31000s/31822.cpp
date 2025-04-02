#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int n, count = 0;
    cin >> str >> n;

    str = str.substr(0, 5);
    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        temp = temp.substr(0, 5);
        if(temp == str)
        {
            count++;
        }
    }
    
    cout << count;
}