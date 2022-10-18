#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    priority_queue <int, vector<int>, greater<int>> num1;
    priority_queue <int> num2;

    int query;
    cin >> query;

    while(query--)
    {
        int value;
        cin >> value;
        
        if(value == 0)
        {
            if(num1.empty() && num2.empty())
            {
                cout << "0\n";
            }
            else
            {
                int n1 = INT32_MAX;
                int n2 = INT32_MAX;
                if(!num1.empty())
                {
                    n1 = num1.top();
                }
                if(!num2.empty())
                {
                    n2 = num2.top() * -1;
                }
                
                if(n1 < n2)
                {
                    cout << num1.top() << "\n";
                    num1.pop();
                }
                else
                {
                    cout << num2.top() << "\n";
                    num2.pop();
                }
            }
        }
        else
        {
            if(value < 0)
            {
                num2.push(value);
            }
            else
            {
                num1.push(value);
            }
        }
    }
}