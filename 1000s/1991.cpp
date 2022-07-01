#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node
{
    char name;
    char left;
    char right;
};

vector <node> nodes(27);


void preOrder (char nodename)
{
    cout << nodes[nodename - 'A'].name;
    
    if(nodes[nodename - 'A'].left != '.')
    {
        preOrder(nodes[nodename - 'A'].left);
    }
    if(nodes[nodename - 'A'].right != '.')
    {
        preOrder(nodes[nodename - 'A'].right);
    }
    return;
}

void inOrder (char nodename)
{
    if(nodes[nodename - 'A'].left != '.')
    {
        inOrder(nodes[nodename - 'A'].left);
    }

    cout << nodes[nodename - 'A'].name;
    
    if(nodes[nodename - 'A'].right != '.')
    {
        inOrder(nodes[nodename - 'A'].right);
    }
    return;
}

void postOrder (char nodename)
{
    if(nodes[nodename - 'A'].left != '.')
    {
        postOrder(nodes[nodename - 'A'].left);
    }
    if(nodes[nodename - 'A'].right != '.')
    {
        postOrder(nodes[nodename - 'A'].right);
    }
    
    cout << nodes[nodename - 'A'].name;

    return;
}

int main()
{
    int n;

    cin >> n;

    char nodename;
    char leftname;
    char rightname;

    for(int i = 0; i < n; i++)
    {
        cin >> nodename >> leftname >> rightname;

        nodes[nodename - 'A'].name = nodename;
        nodes[nodename - 'A'].left = leftname;
        nodes[nodename - 'A'].right = rightname;
    }

    preOrder('A');
    cout << endl;

    inOrder('A');
    cout << endl;

    postOrder('A');
   
}