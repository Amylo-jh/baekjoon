#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> tree;
vector <vector <int>> tree_maxsum;
int max_depth;

int find_max(int posx, int posy)
{
    int max_value = 0;

    if(tree_maxsum[posx][posy] == -1)
    {
        if(posx == max_depth -1)
        {
            tree_maxsum[posx][posy] = tree[posx][posy];
            return tree_maxsum[posx][posy];
        }
        else
        {
            int right = 0;
            int left = 0;

            right = tree[posx][posy] + find_max(posx + 1, posy + 1);
            left = tree[posx][posy] + find_max(posx + 1, posy);

            if(right > left)
            {
                tree_maxsum[posx][posy] = right;
            }
            else
            {
                tree_maxsum[posx][posy] = left;
            }
        }
    }

    return tree_maxsum[posx][posy];
}

int main()
{
    int n;
    cin >> n;
    max_depth = n;

    for(int i = 0; i < n; i++)
    {
        vector <int> temp;
        vector <int> temp_maxsum;
        for(int j = 0; j <= i; j++)
        {
            int tmp = -1;
            temp_maxsum.push_back(tmp);
            cin >> tmp;
            temp.push_back(tmp);

        }
        tree.push_back(temp);
        tree_maxsum.push_back(temp_maxsum);
    }

    int max_value = 0;

    max_value = find_max(0, 0);

    cout << max_value;


}