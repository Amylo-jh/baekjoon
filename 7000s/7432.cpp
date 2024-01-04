#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class filesystem
{
private:
    map <string, filesystem*> child;

public:
    void insert(vector <string> &arr, int index)
    {
        if(index == arr.size())
        {
            return;
        }
        else if(child.find(arr[index]) == child.end())
        {
            child[arr[index]] = new filesystem();
        }

        child[arr[index]]->insert(arr, index+1);
    }

    void output(int depth)
    {
        for(auto ch : child)
        {
            for(int i = 0; i < depth; i++)
            {
                cout << " ";
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

    filesystem* fs = new filesystem;
    
    for(int i = 0; i < n; i++)
    {
        vector <string> arr;
        string str;
        cin >> str;

        int index = 0;
        while(str.find('\\') != string::npos)
        {
            index = str.find('\\');
            string substr = str.substr(0, index);
            arr.push_back(substr);
            str = str.substr(index+1, str.length() - index+1);
            index = 0;
        }
        arr.push_back(str);

        fs->insert(arr, 0);
    }

    fs->output(0);
}