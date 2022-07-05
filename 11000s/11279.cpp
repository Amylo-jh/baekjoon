#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue <int> max_heap;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if(temp)
        {
            max_heap.push(temp);
        }
        else
        {
            if(max_heap.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << max_heap.top() << "\n";
               max_heap.pop();
            }
        }
    }
}