#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 1, k = 1;
    long long answer;
    while(true)
    {
        cin >> n >> k;
        answer = 1;
        
        if(n + k == 0)
        {
            break;
        }
        
        if(n-k < k)
        {
            k = n - k;
        }

        for(int i = 0; i < k; i++)
        {
            answer = answer * n--;
            answer = answer / (i+1);
        }
        cout << answer << "\n";
    }
}