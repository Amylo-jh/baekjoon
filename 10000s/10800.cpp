#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ball
{
    int weight, color, index;
};

int answer[200001] = {0};
int color[200001] = {0};
int weight[2001] = {0};

bool comp(ball a, ball b)
{
    if(a.weight == b.weight)
    {
        return a.color < b.color;
    }

    return a.weight < b.weight;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector <ball> arr;
    for(int i = 0; i < n; i++)
    {
        int color, weight;
        cin >> color >> weight;
        arr.push_back({weight, color, i});
    }
    sort(arr.begin(), arr.end(), comp);

    int total_sum = 0;
    for(int i = 0; i < n; i++)
    {
        int c_weight = arr[i].weight;
        int c_color = arr[i].color;
        int c_index = arr[i].index;

        color[c_color] += c_weight;
        weight[c_weight] += c_weight;
        total_sum += c_weight;

        answer[c_index] = total_sum - color[c_color] - weight[c_weight] + c_weight;
        if(i != 0 && arr[i-1].color == c_color && arr[i-1].weight == c_weight)
        {
            answer[c_index] = answer[arr[i-1].index];
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << answer[i] << "\n";
    }
}