#include <iostream>
#include <vector>

using namespace std;

vector <int> root;

int find(int a)
{
    if(root[a] ^ a)
    {
        root[a] = find(root[a]);
        return root[a];
    }
    return a;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    
    for(int q = 1; q <= tc; q++)
    {
        int person, relation;
        cin >> person >> relation;

        root.resize(person);
        
        for(int i = 0; i < person; i++)
        {
            root[i] = i;
        }

        for(int i = 0; i < relation; i++)
        {
            int a, b;
            cin >> a >> b;

            int root_a = find(a);
            int root_b = find(b);

            if(root_a ^ root_b)
            {
                root[root_a] = root_b;
            }
        }

        int query;
        cin >> query;

        cout << "Scenario " << q << ":" << "\n";
        for(int i = 0; i < query; i++)
        {
            int a, b;
            cin >> a >> b;
            int root_a = find(a);
            int root_b = find(b);

            if(root_a ^ root_b)
            {
                cout << "0\n";   
            }
            else
            {
                cout << "1\n";
            }
        }

        cout << "\n";
    }
}