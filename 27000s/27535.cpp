#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

void base_conversion(int target_num, int base)
{
    if(base < 2 || target_num == 0)
    {
        cout << target_num;
        return;
    }

    stack <int> base_conversion_stack;
    while(target_num > 0)
    {
        int num = target_num % base;
        target_num /= base;
        base_conversion_stack.push(num);
    }
    while(!base_conversion_stack.empty())
    {
        cout << base_conversion_stack.top();
        base_conversion_stack.pop();
    }
}

bool comp(pair <int, char> a, pair <int, char> b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }
    
    return a.first > b.first;
}

int main()
{
    int h, t, c, k, g, m;
    int prev_sum = 0;
    int curr_sum = 0;
    cin >> h >> t >> c >> k >> g >> m;
    prev_sum = h + t + c + k + g;

    for(int i = 0; i < m; i++)
    {
        vector <pair <int, char>> remain_choco(5);
        int h_, t_, c_, k_, g_;
        cin >> h_ >> t_ >> c_ >> k_ >> g_;
        curr_sum = prev_sum - (h_+ t_+ c_+ k_+ g_);
        h -= h_;
        t -= t_;
        c -= c_;
        k -= k_;
        g -= g_;

        remain_choco[0] = {h, 'H'};
        remain_choco[1] = {t, 'T'};
        remain_choco[2] = {c, 'C'};
        remain_choco[3] = {k, 'K'};
        remain_choco[4] = {g, 'G'};
        sort(remain_choco.begin(), remain_choco.end(), comp);

        int set_base = prev_sum % 10;
        base_conversion(curr_sum, set_base);
        cout << "7H\n";

        for(int i = 0; i < 5; i++)
        {
            if(remain_choco[0].first == 0)
            {
                cout << "NULL";
                break;
            }
            if(remain_choco[i].first == 0)
            {
                continue;
            }

            cout << remain_choco[i].second;
        }
        cout << "\n";
        prev_sum = curr_sum;
    }
}