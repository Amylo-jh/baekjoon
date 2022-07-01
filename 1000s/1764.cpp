#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map <string, int> people;
    int n, m;
    int count = 0;
    cin >> n >> m;

    for(int i = 0 ; i < n + m; i++)
    {
        string temp;
        cin >> temp;

        auto [iter, success] = people.insert({temp, 1});
        if(success == false)
        {
            iter->second++;
            count++;
        }
    }

    cout << count << endl;

    for(auto iter : people)
    { 
        if(iter.second > 1)
        {
            cout << iter.first << "\n";
        }
    }
}