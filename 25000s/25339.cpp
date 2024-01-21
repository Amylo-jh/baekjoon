#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    int answer = 0;
    cin >> n >> q;
    for(int i = 0; i < q; i++)
    {
        int query, a, b;
        cin >> query >> a >> b;

        if(query == 1)
        {
            answer = answer ^ 1;
        }
        else
        {
            if(((b - a + 1) / 2) % 2 == 1)
            {
                answer = answer ^ 1;
            }
        }

        cout << answer << "\n";
    }
}