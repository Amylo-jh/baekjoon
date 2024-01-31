#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc;
    cin >> tc;

    while(tc--)
    {
        priority_queue <int> lo;
        priority_queue <int, vector <int>, greater<>> hi;
        int mid;
        int n;
        cin >> n;
        cin >> mid;

        cout << n/2+1 << "\n";
        cout << mid << " ";

        int output_count = 1;
        for(int i = 0; i < n/2; i++)
        {
            int a, b;
            int lo_count = 0;
            int hi_count = 0;
            int same_count = 0;

            cin >> a >> b;

            if(mid < a)
            {
                hi_count++;
            }
            else if(a < mid)
            {
                lo_count++;
            }
            if(mid < b)
            {
                hi_count++;
            }
            else if(b < mid)
            {
                lo_count++;
            }

            if(hi_count < lo_count)
            {
                hi.push(mid);
                lo.push(a);
                lo.push(b);
                mid = lo.top();
                lo.pop();
            }
            else if(hi_count > lo_count)
            {
                lo.push(mid);
                hi.push(a);
                hi.push(b);
                mid = hi.top();
                hi.pop();
            }
            else
            {
                lo.push(min(a, b));
                hi.push(max(a, b));
            }

            cout << mid << " ";
            output_count++;

            if(output_count == 10)
            {
                output_count = 0;
                cout << "\n";
            }
        }
        cout << "\n";
    }
}