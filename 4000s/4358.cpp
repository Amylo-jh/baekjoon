#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map <string, int> trees;
    int total_tree = 0;

    while(1)
    {
        string temp;
        getline(cin, temp);
    
        if(cin.eof() == true)
        {
            break;
        }
    
        trees[temp]++;
        total_tree++;
    }

    cout << fixed;
    cout.precision(4);

    for(auto& iter : trees)
    {
        double percent = double(iter.second) / double(total_tree) * 100;
        cout << iter.first << " " << percent << "\n";
    }
}