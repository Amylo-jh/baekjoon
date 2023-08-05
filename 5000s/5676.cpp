#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> arr;
vector <int> seg;

int init(int start, int end, int node)
{
    if(start == end)
    {
        return seg[node] = arr[start];
    }

    int mid = (start + end) / 2;

    int left = init(start, mid, node*2);
    int right = init(mid+1, end, node*2+1);

    if(left == 0 || right == 0)
    {
        return seg[node] = 0;
    }
    else
    {
        if(left == -1 && right == -1)
        {
            return seg[node] = 1;
        }
        else if(left == 1 && right == 1)
        {
            return seg[node] = 1;
        }
        else
        {
            return seg[node] = -1;
        }
    }
}

int update(int start, int end, int node, int pos, int value)
{
    if(pos < start || end < pos)
    {
        return seg[node];
    }
    if(start == end)
    {
        return seg[node] = value;
    }
    if(start <= pos && pos <= end)
    {
        if(value == 0)
        {
            seg[node] = 0;
        }
        else if(value == -1)
        {
            if(seg[node] == -1)
            {
                seg[node] = 1;
            }
        }
    }

    int mid = (start + end) / 2;
    int left_update = update(start, mid, node*2, pos, value);
    int right_update = update(mid+1, end, node*2+1, pos, value);

    int return_value;
    if(left_update == 0 || right_update == 0)
    {
        return_value = 0;
    }
    else if((left_update == 1 && right_update == 1) || (left_update == -1 && right_update == -1))
    {
        return_value = 1;
    }
    else
    {
        return_value = -1;
    }

    return seg[node] = return_value;
}

int get(int start, int end, int left, int right, int node)
{
    if(right < start || end < left)
    {
        return 32;
    }
    if(left <= start && end <= right)
    {
        return seg[node];
    }

    int mid = (start + end) / 2;
    int left_return = get(start, mid, left, right, node*2);
    int right_return = get(mid+1, end, left, right, node*2+1);
    
    int return_num;

    if(left_return == 0 || right_return == 0)
    {
        return_num = 0;
    }
    else if(left_return == 32)
    {
        return_num = right_return;
    }
    else if(right_return == 32)
    {
        return_num = left_return;
    }
    else
    {
        if((left_return == 1 && right_return == 1) || (left_return == -1 && right_return == -1))
        {
            return_num = 1;
        }
        else
        {
            return_num = -1;
        }
    }

    if(return_num < 0)
    {
        return -1;
    }
    else if(return_num > 0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int n, k;
    while(cin >> n >> k)
    {
        arr.resize(n);
        seg.resize(n*4);
        arr.assign(n, 0);
        seg.assign(n*4, 0);

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(arr[i] > 0)
            {
                arr[i] = 1;
            }
            else if(arr[i] < 0)
            {
                arr[i] = -1;
            }
        }

        init(0, n-1, 1);

        for(int i = 0; i < k; i++)
        {
            char command;
            int a, b;
            cin >> command >> a >> b;
            if(command == 'C')
            {
                if(b < 0)
                {
                    b = -1;
                }
                else if(b > 0)
                {
                    b = 1;
                }
                update(0, n-1, 1, a-1, b);
                arr[a-1] = b;
            }
            else
            {
                int temp = get(0, n-1, a-1, b-1, 1);
                if(temp == 0)
                {
                    cout << "0";
                }
                else if(temp > 0)
                {
                    cout << "+";
                }
                else if(temp < 0)
                {
                    cout << "-";
                }
            }
        }

        cout << "\n";
    }
}