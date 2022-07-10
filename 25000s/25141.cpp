#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector <int> arr;
vector <bool> bool_arr;
stack <int> stk;
int k;
string str;
int x;
int z;

void init(int depth, int curr_index, int priv_sum)
{    
    for(int i = curr_index; i < k-(x-depth); i++)
    {
        stk.push(i);

        if(depth != x)
        {
            int curr_sum = priv_sum + arr[i];
            init(depth+1, i+1, curr_sum);
        }
        else if(priv_sum + arr[i] == z)
        {
            bool_arr.assign(k, false);
            stack <int> temp_stk = stk;
            while(!temp_stk.empty())
            {
                int temp = temp_stk.top();
                temp_stk.pop();
                bool_arr[temp] = true;
            }

            for(int j = 0; j < k; j++)
            {
                if(bool_arr[j])
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }
            cout << "\n";
        }

        stk.pop();
    }

    return;
}

int main()
{    
    cin >> k >> str >> x >> z;

    for(int i = 0; i < k; i++)
    {
        int temp = stoi(str.substr(i, 1));
        arr.push_back(temp);
        bool_arr.push_back(false);
    }

    //depth, curr_index, priv_sum
    init(1, 0, 0);
}