#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k;
    string str;
    cin >> n >> k >> str;
    int count = n-k;

    stack <int> arr;
    for(int i = 0; i < str.length(); i++)
    {
        int temp = str[i] - 48;
        while(k > 0 && !arr.empty() && arr.top() < temp)
        {
            arr.pop();
            k--;
        }
        if(arr.size() >= count && arr.top() > temp)
        {
            k--;
        }
        else
        {
            arr.push(temp);
        }
    }

    stack <int> temp_stack;
    for(int i = 0; i < count; i++)
    {
        temp_stack.push(arr.top());
        arr.pop();
    }
    for(int i = 0; i < count; i++)
    {
        cout << temp_stack.top();
        temp_stack.pop();
    }
}