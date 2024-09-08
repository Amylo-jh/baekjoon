#include <iostream>
#include <string>

using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        int n = 0;
        string s1, s2;
        cin >> s1 >> s2;

        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i])
            {
                n++;
            }
        }

        cout << "Hamming distance is " << n << ".\n";
    }
}