#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long sum = 0;
    long long cent = 0;
    string str;
    while(getline(cin, str))
    {
        string str_euro = str.substr(0, str.find('.'));
        string str_cent = str.substr(str.find('.') + 1);
        long long euro = stoll(str_euro);
        long long eurocent = stoll(str_cent);
        cent += eurocent;
        sum += euro;
    }

    sum += cent / 100;
    cent %= 100;
    cout << sum << '.';

    if(cent < 10)
    {
        cout << '0';
    }
    cout << cent;
}