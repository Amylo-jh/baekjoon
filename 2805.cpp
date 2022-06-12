#include <iostream>
#include <vector>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (b) : (a))

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <long long> trees;
    int n;
    long long target;
    cin >> n >> target;

    long long min_height = 0;
    long long max_height = 0;
    long long middle_height;
    long long sum = 0;

    for(int i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        max_height = max(temp, max_height);
        trees.push_back(temp);
    }

    while(min_height <= max_height)
    {
        sum = 0;
        middle_height = (min_height + max_height) / 2;

        for(int tree : trees)
        {
            if(tree - middle_height <= 0)
            {
                continue;
            }
            else
            {
                sum += tree - middle_height;
            }
            
        }

        if(sum >= target)
        {
            min_height =  middle_height + 1;
        }
        else
        {
            max_height = middle_height - 1;
        }
    }

    cout << max_height;
}