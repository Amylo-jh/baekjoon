#include <iostream>

using namespace std;

int main()
{
    int max_ppl = 0;
    int curr_ppl = 0;
    for(int i = 0; i < 10; i++)
    {
        int a, b;
        cin >> a >> b;
        curr_ppl -= a;
        curr_ppl += b;
        curr_ppl %= 10000;
        max_ppl = max(max_ppl, curr_ppl);
    }

    cout << max_ppl;
}