#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    vector <string> arr(4);
    for(int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    set <string> st;
    vector <string> result;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            string new_str = arr[i] + " " + arr[j];
            st.insert(new_str);
        }
    }

    for(auto i : st)
    {
        result.push_back(i);
    }
    sort(result.begin(), result.end());
    for(auto i : result)
    {
        cout << i << "\n";
    }
}