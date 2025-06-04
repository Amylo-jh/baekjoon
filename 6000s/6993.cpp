#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        string str;
        int shift;
        cin >> str >> shift;
        cout << "Shifting " << str << " by " << shift << " positions gives us: ";
        for(int i = str.length()-shift; i < str.length(); i++)
        {
            cout << str[i];
        }
        for(int i = 0; i < str.length()-shift; i++)
        {
            cout << str[i];
        }
        cout << "\n";
    }
}