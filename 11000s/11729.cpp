#include <iostream>
#include <cmath>

using namespace std;

void print_move(int from, int to)
{
    cout << from << " " << to << "\n";
}

void move_tower(int n, int from, int by, int to)
{
    if(n == 0)
    {
        return;
    }
    
    move_tower(n-1, from, to, by);
    print_move(from, to);
    move_tower(n-1, by, from, to);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << int(pow(2, n))-1 << "\n";
    move_tower(n, 1, 2, 3);
}