#include <iostream>
#include <vector>

using namespace std;

vector <int> arr;

void postorder(int start, int end)
{
    if(start >= end)
    {
        return;
    }
    if(start == end-1)
    {
        cout << arr[start] << "\n";
        return;
    }

    int index = start + 1;
    while(index < end && arr[index] < arr[start])
    {
        index++;
    }

    postorder(start+1, index);
    postorder(index, end);
    cout << arr[start] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int temp;
    while(cin >> temp)
    {
        arr.push_back(temp);
    }

    postorder(0, arr.size());
}