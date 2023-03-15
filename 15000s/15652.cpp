#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <bool> arr;
int n, m;

void backtracking(vector <int> vec, int start, int depth)
{
    if(depth == 0)
    {
        for(int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    vec.push_back(0);
    int vec_size = vec.size();
    for(int i = start; i <= n; i++)
    {
        vec[vec_size-1] = i;
        backtracking(vec, i, depth-1);
    }
}


int main()
{
    cin >> n >> m;

    arr.resize(n+1);
    arr[0] = true;
    
    for(int i = 1; i <= n; i++)
    {
        arr[i-1] = true;
        
        vector <int> vec = {i};
        
        backtracking(vec, i, m-1);

        arr[i-1] = false;
    }
}