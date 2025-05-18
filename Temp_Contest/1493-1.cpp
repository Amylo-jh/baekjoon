#include <iostream>

using namespace std;

int main()
{
    int s, c, o ,n;
    cin >> s >> c >> o >> n;
    s += n;
    c += 2*o;
    cout << min(s/3, c/6);
}