#include <iostream>

using namespace std;

int main()
{
    int br, bc, dr, dc, jr, jc;
    cin >> br >> bc >> dr >> dc >> jr >> jc;

    int dist_b = max(abs(br - jr), abs(bc - jc));
    int dist_d = abs(dr - jr) + abs(dc - jc);

    if (dist_b < dist_d)
    {
        cout << "bessie";
    }
    else if (dist_b > dist_d)
    {
        cout << "daisy";
    }
    else
    {
        cout << "tie";
    }
}