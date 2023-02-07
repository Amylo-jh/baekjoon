#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info
{
    int korean;
    int english;
    int math;
    string name;
};

bool comp(info a, info b)
{
    if(a.korean == b.korean)
    {
        if(a.english == b.english)
        {
            if(a.math == b.math)
            {
                return a.name < b.name;
            }
            else
            {
                return a.math > b.math;
            }
        }
        else
        {
            return a.english < b.english;
        }
    }
    else
    {
        return a.korean > b.korean;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector <info> scores(n);
    for(int i = 0; i < n; i++)
    {
        cin >> scores[i].name >> scores[i].korean >> scores[i].english >> scores[i].math;
    }

    sort(scores.begin(), scores.end(), comp);

    for(int i = 0; i < n; i++)
    {
        cout << scores[i].name << "\n";
    }
}