#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map <string, string> password_list;
    for(int i = 0; i < n; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;
        password_list.insert({str1, str2});
    }
    for(int i = 0; i < m; i++)
    {
        string str1;
        cin >> str1;
        cout << password_list.at(str1) << "\n";
    }
}