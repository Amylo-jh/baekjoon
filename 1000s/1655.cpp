#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue <int> smaller;
    priority_queue <int, vector <int>, greater<> > bigger;

    int small_counter = 0;
    int big_counter = 0;
    int mid_value = 0;
    int high_value = 0;

    {
        int temp;
        cin >> temp;
        smaller.push(temp);
        small_counter++;
        cout << temp << "\n";
        mid_value = temp;
    }
    for(int i = 1; i < n; i++)
    {
        int num;
        cin >> num;

        if(small_counter == big_counter)
        {
            if(high_value < num)
            {
                smaller.push(bigger.top());
                bigger.pop();
                bigger.push(num);
            }
            else
            {
                smaller.push(num);
            }
            small_counter++;
        }
        else
        {
            if(bigger.empty())
            {
                if(mid_value >= num)
                {
                    bigger.push(smaller.top());
                    smaller.pop();
                    smaller.push(num);
                }
                else
                {
                    bigger.push(num);
                }
            }
            else if(mid_value >= num)
            {
                bigger.push(smaller.top());
                smaller.pop();
                smaller.push(num);
            }
            else
            {
                bigger.push(num);
            }
            big_counter++;
        }

        mid_value = smaller.top();
        high_value = bigger.top();
        cout << mid_value << "\n";
    }
}