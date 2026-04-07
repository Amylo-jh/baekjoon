#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, max_value = INT32_MAX, answer = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp > max_value)
        {
            answer += tmp - max_value;
        }
        else
        {
            max_value = tmp;
        }
    }
    cout << answer;
}