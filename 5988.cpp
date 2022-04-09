#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    for(int q = 0; q < tc; q++)
    {
        string temp;
        cin >> temp;

        int n = temp.length();
        string last_str = temp.substr(n-1, 1);
        int i = stoi(last_str);

        if(i % 2)
        {
            cout << "odd" << endl;
        }
        else
        {
            cout << "even" << endl;
        }
    }
}