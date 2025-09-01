#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int temp, num = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        num += temp;
    }
    cout << min(n-num, num);
}