#include <iostream>

using namespace std;

int main()
{
    int w, h, n, m;
    cin >> w >> h >> n >> m;
    int x = (w / (n+1)) + ((w % (n+1))?1:0);
    int y = (h / (m+1)) + ((h % (m+1))?1:0);
    cout << x * y;
}