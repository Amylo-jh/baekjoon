#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> inorder;
vector <int> postorder;
vector <int> cache;

void parse_preorder(int inorder_start, int postorder_start, int postorder_end)
{
    int inRoot = 0;
    if(postorder_start <= postorder_end)
    {
        cout << postorder[postorder_end] << " ";
        inRoot = cache[postorder[postorder_end]];
     
        parse_preorder(inorder_start, postorder_start, postorder_start+inRoot-1-inorder_start);
        parse_preorder(inRoot+1, postorder_start+inRoot-inorder_start, postorder_end-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    inorder.resize(n+1);
    postorder.resize(n+1);
    cache.resize(n+1);

    for(int i = 1; i <= n; i++)
    {
        cin >> inorder[i];
        cache[inorder[i]] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> postorder[i];
    }

    parse_preorder(1, 1, n);
}