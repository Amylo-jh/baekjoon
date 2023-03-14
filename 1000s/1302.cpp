#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map <string, int> books;

    int max_book = 0;
    string max_title = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        books[str]++;

        if(max_book < books[str])
        {
            max_title = str;
            max_book = books[str];
        }
        else if(max_book == books[str])
        {
            max_title = min(max_title, str);
        }
    }

    cout << max_title;
}