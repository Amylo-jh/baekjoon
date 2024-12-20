#include <iostream>

using namespace std;    

int main()
{
    int k, w, m;
    cin >> k >> w >> m;

    int answer = (w-k)/m;
    if((w-k)%m != 0)
    {
        answer++;
    }
    cout << max(0, answer);
}