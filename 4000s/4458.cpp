#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++)
    {
        string temp_str;
        getline(cin, temp_str);
        if(temp_str[0] >= 97)
        {
            temp_str[0] -= 32;
        }
        cout << temp_str << "\n";
    }
}