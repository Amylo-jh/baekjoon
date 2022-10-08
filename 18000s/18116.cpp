#include <iostream>
#include <vector>

using namespace std;

struct part
{
    int root;
    int count;
}

part[1000001];

int find(int a)
{
    if(part[a].root == a)
    {
        return a;
    }
    part[a].root = find(part[a].root);
    return part[a].root;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i <= 1000000; i++)
    {
        part[i].root = i;
        part[i].count = 1;
    }

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        char instruction;
        cin >> instruction;

        if(instruction == 'I')
        {
            int a, b;
            cin >> a >> b;
            
            int parent_a = find(a);
            int parent_b = find(b);

            if(parent_a != parent_b)
            {
                part[parent_a].root = parent_b;
                part[parent_b].count += part[parent_a].count;
                part[parent_a].count = 0;
            }
        }
        else
        {
            int a;
            cin >> a;
            cout << part[find(a)].count << "\n";
        }
    }
}