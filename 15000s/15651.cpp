#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <int> seq;

void print_seq()
{
    for(int a : seq)
    {
        cout << a << " ";
    }
    cout << "\n";
}

void sol(int a, int b)
{
    for(int i = 1; i <= n; i++)
    {
        seq[a-1] = i;

        if(b == m)
        {
            print_seq();
        }
        else
        {
            sol(a+1, b+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        seq.push_back(0);
    }
 
    sol(1, 1);
}