#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    for (auto ch : str)
    {
        int it = ch;
        it -= 3;
        if (it < 'A')
        {
            it += 'Z' - 'A'+1;
        }
        cout << char(it);
    }
}