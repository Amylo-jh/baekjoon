#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class AntHome
{
private:
    map<string, AntHome*> child;

public:
    void insert(vector <string>& foods, int index)
    {
        if(index == foods.size())
        {
            return;
        }
        else if(child.find(foods[index]) == child.end())
        {
            child[foods[index]] = new AntHome();
        }

        child[foods[index]]->insert(foods, index+1);
    }

    void output(int depth)
    {
        for(auto ch : child)
        {
            for(int i = 0; i < depth; i++)
            {
                cout << "--";
            }
            cout << ch.first << "\n";
            ch.second->output(depth+1);
        }
    }
};

int main()
{
    int n;
    cin >> n;

    AntHome* root = new AntHome;
    for(int i = 0; i < n; i++)
    {
        int depth;
        cin >> depth;

        vector <string> foods(depth);
        for(int j = 0; j < depth; j++)
        {
            cin >> foods[j];
        }
        root->insert(foods, 0);
    }

    root->output(0);
}